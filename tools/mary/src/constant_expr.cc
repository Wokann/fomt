#include "constant_expr.hh"

#include <cctype>
#include <limits>
#include <stdexcept>
#include <string>

namespace mary
{
namespace
{

constexpr Integer lowest = std::numeric_limits<Integer>::min();
constexpr Integer highest = std::numeric_limits<Integer>::max();

[[noreturn]] void fail(const std::string &text)
{
    throw std::runtime_error(text);
}

Integer number(std::string_view token)
{
    auto digits = token;
    while (!digits.empty() && (digits.back() == 'u' || digits.back() == 'U' ||
                               digits.back() == 'l' || digits.back() == 'L'))
        digits.remove_suffix(1);
    std::string suffix(token.substr(digits.size()));
    for (auto &c : suffix)
        c = char(std::tolower(static_cast<unsigned char>(c)));
    if (suffix != "" && suffix != "u" && suffix != "l" && suffix != "ul" && suffix != "lu" &&
        suffix != "ll" && suffix != "ull" && suffix != "llu")
        fail("invalid integer suffix '" + suffix + "'");
    unsigned radix = 10;
    if (digits.size() > 1 && digits.front() == '0')
    {
        if (digits[1] == 'x' || digits[1] == 'X')
        {
            radix = 16;
            digits.remove_prefix(2);
        }
        else if (digits[1] == 'b' || digits[1] == 'B')
        {
            radix = 2;
            digits.remove_prefix(2);
        }
        else
        {
            radix = 8;
            digits.remove_prefix(1);
        }
    }
    if (digits.empty())
        fail("empty integer literal");
    Integer value = 0;
    for (unsigned char c : digits)
    {
        unsigned n = c >= '0' && c <= '9'   ? unsigned(c - '0')
                     : c >= 'a' && c <= 'f' ? unsigned(c - 'a') + 10
                     : c >= 'A' && c <= 'F' ? unsigned(c - 'A') + 10
                                            : 255;
        if (n >= radix || value > (highest - n) / radix)
            fail("invalid or overflowing integer '" + std::string(token) + "'");
        value = value * radix + n;
    }
    return value;
}

class Expression
{
  public:
    Expression(std::string_view text, const ConstantLookup &lookup, bool undefined)
      : input(text)
      , lookup(lookup)
      , undefined(undefined)
    {
    }

    Integer parse()
    {
        auto value = expression(0, true);
        space();
        if (at != input.size())
            fail("unexpected constant expression text '" + std::string(input.substr(at)) + "'");
        return value;
    }

  private:
    std::string_view input;
    const ConstantLookup &lookup;
    bool undefined;
    std::size_t at = 0;
    unsigned depth = 0;

    void space()
    {
        while (at < input.size() && std::isspace(static_cast<unsigned char>(input[at])))
            ++at;
    }
    bool eat(std::string_view value)
    {
        space();
        if (input.substr(at, value.size()) != value)
            return false;
        at += value.size();
        return true;
    }

    Integer character()
    {
        ++at;
        if (at == input.size())
            fail("unterminated character constant");
        unsigned char c = input[at++];
        Integer value = c;
        if (c == '\\')
        {
            if (at == input.size())
                fail("unterminated character escape");
            c = input[at++];
            switch (c)
            {
                case 'n':
                    value = 10;
                    break;
                case 'r':
                    value = 13;
                    break;
                case 't':
                    value = 9;
                    break;
                case 'a':
                    value = 7;
                    break;
                case 'b':
                    value = 8;
                    break;
                case 'f':
                    value = 12;
                    break;
                case 'v':
                    value = 11;
                    break;
                case '\\':
                case '\'':
                case '"':
                case '?':
                    value = c;
                    break;
                default:
                    if (c == 'x')
                    {
                        const auto start = at;
                        while (at < input.size() &&
                               std::isxdigit(static_cast<unsigned char>(input[at])))
                            ++at;
                        if (at == start)
                            fail("empty hexadecimal character escape");
                        value = number("0x" + std::string(input.substr(start, at - start)));
                    }
                    else if (c >= '0' && c <= '7')
                    {
                        value = c - '0';
                        for (unsigned n = 0;
                             n < 2 && at < input.size() && input[at] >= '0' && input[at] <= '7';
                             ++n)
                            value = value * 8 + input[at++] - '0';
                    }
                    else
                        fail("unsupported character escape");
            }
        }
        else if (c >= 128 || c == '\'')
            fail("expected one ASCII character");
        if (at == input.size() || input[at++] != '\'')
            fail("multi-character or unterminated character constant");
        if (value > 255)
            fail("character escape exceeds one byte");
        return value;
    }

    Integer atom()
    {
        space();
        if (at < input.size() && input[at] == '\'')
            return character();
        const auto start = at;
        while (at < input.size() &&
               (std::isalnum(static_cast<unsigned char>(input[at])) || input[at] == '_'))
            ++at;
        auto token = input.substr(start, at - start);
        if (token.empty())
            fail("expected integer or constant name");
        if (std::isdigit(static_cast<unsigned char>(token.front())))
            return number(token);
        if (lookup)
            if (auto value = lookup(token))
                return *value;
        if (undefined)
            return 0;
        fail("unknown constant '" + std::string(token) + "'");
    }

    Integer expression(unsigned minimum, bool active)
    {
        if (++depth > 256)
            fail("constant expression nesting limit exceeded");
        Integer value;
        if (eat("+"))
            value = expression(11, active);
        else if (eat("-"))
        {
            auto rhs = expression(11, active);
            if (active && rhs == lowest)
                fail("integer negation overflow");
            value = active ? -rhs : 0;
        }
        else if (eat("!"))
            value = expression(11, active) == 0;
        else if (eat("~"))
            value = ~expression(11, active);
        else if (eat("("))
        {
            value = expression(0, active);
            if (!eat(")"))
                fail("missing ')' in constant expression");
        }
        else
            value = atom();
        for (;;)
        {
            space();
            std::string_view op;
            for (auto candidate : { "||",
                                    "&&",
                                    "==",
                                    "!=",
                                    "<=",
                                    ">=",
                                    "<<",
                                    ">>",
                                    "|",
                                    "^",
                                    "&",
                                    "<",
                                    ">",
                                    "+",
                                    "-",
                                    "*",
                                    "/",
                                    "%" })
            {
                auto s = std::string_view(candidate);
                if (input.substr(at, s.size()) == s)
                {
                    op = s;
                    break;
                }
            }
            if (op.empty())
                break;
            unsigned priority = op == "||"                                           ? 1
                                : op == "&&"                                         ? 2
                                : op == "|"                                          ? 3
                                : op == "^"                                          ? 4
                                : op == "&"                                          ? 5
                                : op == "==" || op == "!="                           ? 6
                                : op == "<" || op == ">" || op == "<=" || op == ">=" ? 7
                                : op == "<<" || op == ">>"                           ? 8
                                : op == "+" || op == "-"                             ? 9
                                                                                     : 10;
            if (priority < minimum)
                break;
            at += op.size();
            auto rhs = expression(
                priority + 1, active && !(op == "&&" && value == 0) && !(op == "||" && value != 0));
            value = active ? apply_integer_operator(op, value, rhs) : 0;
        }
        if (minimum == 0 && eat("?"))
        {
            auto yes = expression(0, active && value != 0);
            if (!eat(":"))
                fail("missing ':' in constant conditional");
            auto no = expression(0, active && value == 0);
            value = value != 0 ? yes : no;
        }
        --depth;
        return value;
    }
};

} // namespace

Integer apply_integer_operator(std::string_view op, Integer lhs, Integer rhs)
{
    if (op == "+" && !(rhs > 0 && lhs > highest - rhs) && !(rhs < 0 && lhs < lowest - rhs))
        return lhs + rhs;
    if (op == "-" && !(rhs < 0 && lhs > highest + rhs) && !(rhs > 0 && lhs < lowest + rhs))
        return lhs - rhs;
    if (op == "*")
    {
        if (lhs == 0 || rhs == 0)
            return 0;
        if (lhs > 0 ? (rhs > 0 ? lhs <= highest / rhs : rhs >= lowest / lhs)
                    : (rhs > 0 ? lhs >= lowest / rhs : lhs >= highest / rhs))
            return lhs * rhs;
    }
    if ((op == "/" || op == "%") && rhs != 0 && !(lhs == lowest && rhs == -1))
        return op == "/" ? lhs / rhs : lhs % rhs;
    if (op == "<<" && rhs >= 0 && rhs < 64)
    {
        if (rhs == 63)
        {
            if (lhs == 0)
                return 0;
            if (lhs == -1)
                return lowest;
        }
        else
            return apply_integer_operator("*", lhs, Integer(1) << rhs);
    }
    if (op == ">>" && rhs >= 0 && rhs < 64)
        return lhs >= 0 ? lhs >> rhs : -1 - ((-1 - lhs) >> rhs);
    if (op == "|")
        return lhs | rhs;
    if (op == "&")
        return lhs & rhs;
    if (op == "^")
        return lhs ^ rhs;
    if (op == "||")
        return lhs != 0 || rhs != 0;
    if (op == "&&")
        return lhs != 0 && rhs != 0;
    if (op == "==")
        return lhs == rhs;
    if (op == "!=")
        return lhs != rhs;
    if (op == "<")
        return lhs < rhs;
    if (op == ">")
        return lhs > rhs;
    if (op == "<=")
        return lhs <= rhs;
    if (op == ">=")
        return lhs >= rhs;
    fail("invalid or overflowing integer operation: " + std::to_string(lhs) + " " +
         std::string(op) + " " + std::to_string(rhs));
}

Integer evaluate_constant(std::string_view input,
                          const ConstantLookup &lookup,
                          bool undefined_is_zero)
{
    return Expression(input, lookup, undefined_is_zero).parse();
}

} // namespace mary
