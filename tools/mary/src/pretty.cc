#include "pretty.hh"
#include "low_level.hh"

#include <sstream>
#include <stdexcept>

namespace mary
{
namespace
{

std::string escaped(std::string_view text)
{
    std::string out;
    for (auto c : text)
        switch (c)
        {
            case '\a':
                out += "\\a";
                break;
            case '\b':
                out += "\\b";
                break;
            case '\f':
                out += "\\f";
                break;
            case '\v':
                out += "\\v";
                break;
            case '\n':
                out += "\\n";
                break;
            case '\r':
                out += "\\r";
                break;
            case '\t':
                out += "\\t";
                break;
            case '"':
                out += "\\\"";
                break;
            case '\\':
                out += "\\\\";
                break;
            default:
                out += c;
        }
    return out;
}
std::string hex_byte(std::uint8_t byte)
{
    const char hex[] = "0123456789ABCDEF";
    std::string out = "\\x";
    out += hex[byte >> 4];
    out += hex[byte & 15];
    return out;
}
unsigned priority(const Expr &e)
{
    if (e.kind == Expr::Unary)
        return 11;
    if (e.kind != Expr::Binary)
        return 12;
    auto &op = e.name;
    return op == "||"                                           ? 1
           : op == "&&"                                         ? 2
           : op == "==" || op == "!="                           ? 6
           : op == "<" || op == "<=" || op == ">" || op == ">=" ? 7
           : op == "+" || op == "-"                             ? 9
                                                                : 10;
}
std::string expr(const Expr &e, const Charmap *map, bool legacy, unsigned parent = 0)
{
    std::string result;
    switch (e.kind)
    {
        case Expr::Name:
            result = e.name;
            break;
        case Expr::Int:
            result = std::to_string(e.value);
            break;
        case Expr::Str:
            result = "\"";
            for (auto &fragment : string_fragments(e.bytes, map, legacy))
                result += fragment;
            result += '"';
            break;
        case Expr::Unary:
            result = e.name + expr(e.args.at(0), map, legacy, 12);
            break;
        case Expr::Increment:
        {
            auto op = e.value > 0 ? "++" : "--";
            result = (e.value == 2 || e.value == -2) ? op + e.name : e.name + op;
            break;
        }
        case Expr::Binary:
            result = expr(e.args.at(0), map, legacy, priority(e)) + " " + e.name + " " +
                     expr(e.args.at(1), map, legacy, priority(e) + 1);
            break;
        case Expr::Call:
            result = e.name + "(";
            for (std::size_t i = 0; i < e.args.size(); ++i)
            {
                if (i)
                    result += ", ";
                result += expr(e.args[i], map, legacy);
            }
            result += ')';
            break;
    }
    return priority(e) < parent ? "(" + result + ")" : result;
}

class Formatter
{
  public:
    Formatter(bool c, const Charmap *map)
      : c(c)
      , map(map)
    {
    }
    std::string run(const std::vector<Statement> &body, unsigned indent)
    {
        statements(body, indent);
        return out.str();
    }

  private:
    bool c;
    const Charmap *map;
    std::ostringstream out;
    std::vector<bool> controls;
    static std::string pad(unsigned n)
    {
        return std::string(n * 4, ' ');
    }
    std::string expression(const Expr &e)
    {
        return expr(e, map, !c);
    }
    std::string declaration(const Statement &s)
    {
        std::string result = c ? (s.kind == Statement::Variables ? "int " : "const int ")
                               : (s.kind == Statement::Variables ? "var " : "const ");
        for (std::size_t i = 0; i < s.declarations.size(); ++i)
        {
            if (i)
                result += ", ";
            result += s.declarations[i].first;
            if (s.declarations[i].second)
                result += " = " + expression(*s.declarations[i].second);
        }
        return result;
    }
    std::string inline_statement(const Statement &s)
    {
        if (s.kind == Statement::Variables)
            return declaration(s);
        if (s.kind == Statement::Assign)
            return s.name + " " + s.operation + " " + expression(s.expression);
        if (s.kind == Statement::Expression)
            return expression(s.expression);
        throw std::runtime_error("statement cannot appear in a for clause");
    }
    void block(const std::vector<Statement> &body, unsigned n)
    {
        out << pad(n) << "{\n";
        statements(body, n + 1);
        out << pad(n) << "}\n";
    }
    void statements(const std::vector<Statement> &body, unsigned n)
    {
        bool terminated = false;
        for (auto &s : body)
        {
            if (c && terminated)
                throw std::runtime_error(
                    "unreachable statement cannot be expressed in strict Mary-C");
            statement(s, n);
            terminated = statement_terminates(s);
        }
    }
    void statement(const Statement &s, unsigned n)
    {
        auto semicolon = c ? ";" : "";
        out << pad(n);
        switch (s.kind)
        {
            case Statement::Variables:
                out << declaration(s) << semicolon << '\n';
                break;
            case Statement::Constants:
                for (std::size_t i = 0; i < s.declarations.size(); ++i)
                {
                    auto &entry = s.declarations[i];
                    if (i)
                        out << pad(n);
                    if (!entry.second)
                        throw std::runtime_error("constant without initializer");
                    if (entry.second->kind == Expr::Str)
                    {
                        out << (c ? "const char *" : "const ") << entry.first << " =\n";
                        auto fragments = string_fragments(entry.second->bytes, map, !c);
                        for (std::size_t j = 0; j < fragments.size(); ++j)
                            out << pad(n + 1) << '"' << fragments[j] << '"'
                                << (j + 1 == fragments.size() ? semicolon : "") << '\n';
                    }
                    else
                        out << (c ? "const int " : "const ") << entry.first << " = "
                            << expression(*entry.second) << semicolon << '\n';
                }
                break;
            case Statement::Assign:
                out << s.name << ' ' << s.operation << ' ' << expression(s.expression) << semicolon
                    << '\n';
                break;
            case Statement::AssignNoDiscard:
                out << (c ? "mary_nodisc(" : "nodisc ") << s.name << ' ' << s.operation << ' '
                    << expression(s.expression) << (c ? ");" : "") << '\n';
                break;
            case Statement::Expression:
                if (!c && s.expression.kind != Expr::Increment)
                    out << "discard ";
                out << expression(s.expression) << semicolon << '\n';
                break;
            case Statement::Call:
                out << expression(s.expression) << semicolon << '\n';
                break;
            case Statement::If:
            case Statement::IfElse:
                out << "if " << (c ? "(" : "") << expression(s.expression) << (c ? ")" : "")
                    << '\n';
                block(s.body, n);
                if (s.kind == Statement::IfElse)
                {
                    out << pad(n) << "else\n";
                    block(s.alternative, n);
                }
                break;
            case Statement::For:
                out << "for " << (c ? "(" : "") << inline_statement(s.clauses.at(0)) << "; "
                    << expression(s.expression) << "; " << inline_statement(s.clauses.at(1))
                    << (c ? ")" : "") << '\n';
                controls.push_back(false);
                block(s.body, n);
                controls.pop_back();
                break;
            case Statement::DoWhile:
                out << "do\n";
                controls.push_back(false);
                block(s.body, n);
                controls.pop_back();
                out << pad(n) << "while " << (c ? "(" : "") << expression(s.expression)
                    << (c ? ");" : "") << '\n';
                break;
            case Statement::Switch:
                out << (c ? (s.compact ? "mary_switch_compact (" : "switch (")
                          : (s.compact ? "switch compact " : "switch "))
                    << expression(s.expression) << (c ? ")" : "") << '\n'
                    << pad(n) << "{\n";
                controls.push_back(true);
                for (auto &branch : s.cases)
                {
                    if (c)
                    {
                        if (branch.kind == SwitchCase::Values)
                            for (auto &value : branch.values)
                                out << pad(n + 1) << "case " << expression(value) << ":\n";
                        else
                            out << pad(n + 1)
                                << (branch.kind == SwitchCase::Default ? "default:"
                                    : branch.kind == SwitchCase::ImplicitDefault
                                        ? "mary_implicit_default:"
                                        : "mary_dead_jump:")
                                << '\n';
                        statements(branch.body, n + 2);
                        if ((branch.kind == SwitchCase::Values ||
                             branch.kind == SwitchCase::Default) &&
                            !branch.fallthrough && !sequence_terminates(branch.body))
                            out << pad(n + 2) << "break;\n";
                    }
                    else
                    {
                        out << pad(n + 1);
                        if (branch.kind == SwitchCase::Values)
                        {
                            out << "case ";
                            for (std::size_t i = 0; i < branch.values.size(); ++i)
                            {
                                if (i)
                                    out << ", ";
                                out << expression(branch.values[i]);
                            }
                            if (branch.fallthrough)
                                out << " fallthrough";
                        }
                        else if (branch.kind == SwitchCase::Default)
                            out << (branch.fallthrough ? "default fallthrough" : "default");
                        else
                            out << (branch.kind == SwitchCase::ImplicitDefault ? "default implicit"
                                                                               : "dead");
                        out << '\n';
                        block(branch.body, n + 1);
                    }
                }
                controls.pop_back();
                out << pad(n) << "}\n";
                break;
            case Statement::Break:
                if (c && controls.empty())
                    throw std::runtime_error("break has no enclosing control construct");
                out << (c && !controls.back() ? "mary_break_switch" : "break") << semicolon << '\n';
                break;
            case Statement::Exit:
                out << (c ? "return;" : "exit") << '\n';
                break;
            case Statement::JumpNext:
                if (c)
                    throw std::runtime_error("jump-next cannot be expressed in strict Mary-C");
                out << "jump next\n";
                break;
            case Statement::Ir:
                if (c)
                    throw std::runtime_error("raw IR cannot be expressed in strict Mary-C");
                out << "ir\n" << pad(n) << "{\n" << format_ir(s.raw_ir, n + 1) << pad(n) << "}\n";
                break;
        }
    }
};

} // namespace

std::vector<std::string> string_fragments(const Bytes &bytes, const Charmap *map, bool legacy)
{
    std::vector<std::string> result;
    std::string fragment;
    bool split = false;
    auto start_next = [&]
    {
        if (split && !fragment.empty())
        {
            result.push_back(std::move(fragment));
            fragment.clear();
        }
        split = false;
    };
    for (std::size_t at = 0; at < bytes.size();)
    {
        if (map)
        {
            if (auto decoded = map->decode_one(bytes, at))
            {
                start_next();
                auto &text = decoded->second;
                fragment += Charmap::is_named_escape(text) ? text : escaped(text);
                split = text == "\\n" || text == "\\p";
                at += decoded->first;
                continue;
            }
            start_next();
            auto count = map->raw_sequence_length(bytes, at);
            for (std::size_t n = 0; n < count; ++n)
                fragment += hex_byte(bytes[at++]);
        }
        else
        {
            auto byte = bytes[at++];
            if (byte == '"' || byte == '\\')
                fragment += escaped(std::string(1, char(byte)));
            else if (!legacy && (byte == '\r' || byte == '\n' || byte == '\t'))
                fragment += escaped(std::string(1, char(byte)));
            else if (byte >= 0x20 && byte < 0x7f)
                fragment += char(byte);
            else
                fragment += hex_byte(byte);
        }
    }
    if (!fragment.empty() || result.empty())
        result.push_back(std::move(fragment));
    return result;
}

std::string format_expression(const Expr &e, const Charmap *map, bool legacy)
{
    return expr(e, map, legacy);
}
std::string format_statements(const std::vector<Statement> &statements,
                              bool c,
                              unsigned indent,
                              const Charmap *map)
{
    return Formatter(c, map).run(statements, indent);
}
std::string format_mary_c(const std::string &name,
                          const std::vector<Statement> &statements,
                          const Charmap *map,
                          std::optional<Integer> id)
{
    std::ostringstream out;
    std::size_t texts = 0;
    while (texts < statements.size())
    {
        auto &s = statements[texts];
        if (s.kind != Statement::Constants || s.declarations.size() != 1 ||
            !s.declarations[0].second || s.declarations[0].second->kind != Expr::Str)
            break;
        ++texts;
    }
    if (texts)
    {
        out << "mary_text_table\n{\n";
        for (std::size_t i = 0; i < texts; ++i)
        {
            auto &entry = statements[i].declarations[0];
            out << "    const char " << entry.first << "[] =\n";
            auto fragments = string_fragments(entry.second->bytes, map);
            for (std::size_t j = 0; j < fragments.size(); ++j)
                out << "        \"" << fragments[j] << '"' << (j + 1 == fragments.size() ? ";" : "")
                    << '\n';
            if (i + 1 != texts)
                out << '\n';
        }
        out << "};\n\n";
    }
    if (id)
        out << "mary_script(" << *id << ") ";
    out << "void " << name << "(void)\n{\n";
    std::vector<Statement> body(statements.begin() + texts, statements.end());
    out << format_statements(body, true, 1, map) << "}\n";
    return out.str();
}
std::string format_legacy(Integer id,
                          const std::string &name,
                          const std::vector<Statement> &statements,
                          const Charmap *map)
{
    return "script " + std::to_string(id) + " " + name + "\n{\n" +
           format_statements(statements, false, 1, map) + "}\n";
}

} // namespace mary
