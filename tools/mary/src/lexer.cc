#include "lexer.hh"
#include "constant_expr.hh"

#include <algorithm>
#include <cctype>
#include <charconv>
#include <stdexcept>

namespace mary
{

std::vector<Token> lex(std::string_view source, const Charmap *map, bool legacy)
{
    std::vector<Token> result;
    std::size_t at = 0, line = 1, column = 1;
    auto advance = [&]
    {
        if (source[at++] == '\n')
        {
            ++line;
            column = 1;
        }
        else
            ++column;
    };
    auto starts = [&](std::string_view value) { return source.substr(at, value.size()) == value; };
    auto fail = [&](const std::string &message)
    {
        throw std::runtime_error("line " + std::to_string(line) + ", column " +
                                 std::to_string(column) + ": " + message);
    };
    while (at < source.size())
    {
        unsigned char c = source[at];
        if (std::isspace(c))
        {
            advance();
            continue;
        }
        if (starts("//") || (legacy && c == '#'))
        {
            while (at < source.size() && source[at] != '\n')
                advance();
            continue;
        }
        if (starts("/*"))
        {
            advance();
            advance();
            while (at < source.size() && !starts("*/"))
                advance();
            if (at == source.size())
                fail("unterminated block comment");
            advance();
            advance();
            continue;
        }
        Token token{ TokenKind::Punctuation, "", 0, {}, line, column };
        const auto start = at;
        if (std::isalpha(c) || c == '_')
        {
            token.kind = TokenKind::Identifier;
            do
            {
                advance();
            } while (at < source.size() &&
                     (std::isalnum(static_cast<unsigned char>(source[at])) || source[at] == '_'));
        }
        else if (std::isdigit(c))
        {
            token.kind = TokenKind::Integer;
            do
            {
                advance();
            } while (at < source.size() &&
                     (std::isalnum(static_cast<unsigned char>(source[at])) || source[at] == '_'));
            auto literal = source.substr(start, at - start);
            if (legacy)
            {
                int radix = 10;
                if (literal.substr(0, 2) == "0x")
                {
                    radix = 16;
                    literal.remove_prefix(2);
                }
                auto converted = std::from_chars(
                    literal.data(), literal.data() + literal.size(), token.integer, radix);
                if (converted.ec != std::errc{} || converted.ptr != literal.data() + literal.size())
                    fail("invalid or overflowing legacy integer literal");
            }
            else
                token.integer = evaluate_constant(literal, {});
        }
        else if (c == '\'')
        {
            token.kind = TokenKind::Integer;
            advance();
            while (at < source.size() && source[at] != '\'')
            {
                if (source[at] == '\\')
                    advance();
                if (at < source.size())
                    advance();
            }
            if (at == source.size())
                fail("unterminated character constant");
            advance();
            token.integer = evaluate_constant(source.substr(start, at - start), {});
        }
        else if (c == '"')
        {
            token.kind = TokenKind::String;
            advance();
            std::string text;
            auto flush = [&]
            {
                if (text.empty())
                    return;
                auto bytes = map ? map->encode_text(text) : Bytes(text.begin(), text.end());
                token.bytes.insert(token.bytes.end(), bytes.begin(), bytes.end());
                text.clear();
            };
            while (at < source.size() && source[at] != '"')
            {
                if (source[at] != '\\')
                {
                    text += source[at];
                    advance();
                    continue;
                }
                advance();
                if (at == source.size())
                    fail("unterminated string escape");
                char escape = source[at];
                advance();
                if (escape == 'x')
                {
                    flush();
                    if (at + 2 > source.size())
                        fail("short hexadecimal string escape");
                    auto pair = source.substr(at, 2);
                    if (!std::all_of(pair.begin(),
                                     pair.end(),
                                     [](unsigned char x) { return std::isxdigit(x); }))
                        fail("invalid hexadecimal string escape");
                    token.bytes.push_back(
                        static_cast<std::uint8_t>(evaluate_constant("0x" + std::string(pair), {})));
                    advance();
                    advance();
                }
                else if (map)
                {
                    // Mary-C encodes each named escape independently; the old
                    // DSL includes it in its longest-match textual run.
                    if (!legacy)
                        flush();
                    if (escape != '\\' && escape != '"' && !(legacy && escape == '\n'))
                        text += '\\';
                    text += escape;
                    while (at < source.size() &&
                           (static_cast<unsigned char>(source[at]) & 0xc0) == 0x80)
                    {
                        text += source[at];
                        advance();
                    }
                    if (!legacy)
                        flush();
                }
                else if (legacy)
                {
                    if (escape != '\\' && escape != '"' && escape != '\n')
                        text += '\\';
                    text += escape;
                }
                else
                {
                    text += escape == 'n'   ? '\n'
                            : escape == 'r' ? '\r'
                            : escape == 't' ? '\t'
                                            : escape;
                }
            }
            if (at == source.size())
                fail("unterminated string literal");
            advance();
            flush();
            if (std::find(token.bytes.begin(), token.bytes.end(), 0) != token.bytes.end())
                fail("string literal contains reserved STR terminator 00");
        }
        else
        {
            bool two = false;
            for (auto op : { "+=",
                             "-=",
                             "*=",
                             "/=",
                             "%=",
                             "==",
                             "!=",
                             "<=",
                             ">=",
                             "&&",
                             "||",
                             "<<",
                             ">>",
                             "++",
                             "--" })
                if (starts(op))
                {
                    advance();
                    advance();
                    two = true;
                    break;
                }
            if (!two)
            {
                if (std::string_view("(){}[],;:+-*/%!~=<>|&^?").find(char(c)) ==
                    std::string_view::npos)
                    fail("unexpected source character");
                advance();
            }
        }
        token.text = source.substr(start, at - start);
        result.push_back(std::move(token));
    }
    result.push_back({ TokenKind::End, "", 0, {}, line, column });
    return result;
}

const Token &Tokens::peek(std::size_t lookahead) const
{
    return input.at(std::min(at + lookahead, input.size() - 1));
}
bool Tokens::is(std::string_view value) const
{
    return peek().text == value;
}
bool Tokens::eat(std::string_view value)
{
    if (!is(value))
        return false;
    ++at;
    return true;
}
void Tokens::require(std::string_view value)
{
    if (!eat(value))
        error("expected '" + std::string(value) + "'");
}
Token Tokens::take()
{
    if (end())
        error("unexpected end of input");
    return input[at++];
}
std::string Tokens::identifier()
{
    if (peek().kind != TokenKind::Identifier)
        error("expected identifier");
    return take().text;
}
Integer Tokens::integer()
{
    bool negative = eat("-");
    if (peek().kind != TokenKind::Integer)
        error("expected integer");
    auto value = take().integer;
    return negative ? apply_integer_operator("-", 0, value) : value;
}
void Tokens::error(const std::string &message) const
{
    throw std::runtime_error("line " + std::to_string(peek().line) + ", column " +
                             std::to_string(peek().column) + ": " + message);
}

} // namespace mary
