#include "preprocessor.hh"
#include "constant_expr.hh"
#include "io.hh"

#include <algorithm>
#include <cctype>
#include <iterator>
#include <stdexcept>

namespace mary
{
namespace
{

using Token = PreprocessToken;
using Tokens = std::vector<Token>;

class PreprocessError : public std::runtime_error
{
  public:
    PreprocessError(std::size_t line, const std::string &message)
      : std::runtime_error("line " + std::to_string(line) + ": " + message),
        line(line), message(message)
    {
    }
    std::size_t line;
    std::string message;
};

[[noreturn]] void fail(std::size_t line, const std::string &message)
{
    throw PreprocessError(line, message);
}

bool space(char c)
{
    return std::isspace(static_cast<unsigned char>(c)) != 0;
}
bool alnum(char c)
{
    return std::isalnum(static_cast<unsigned char>(c)) != 0;
}
bool digit(char c)
{
    return std::isdigit(static_cast<unsigned char>(c)) != 0;
}

std::string_view trim(std::string_view s)
{
    while (!s.empty() && space(s.front()))
        s.remove_prefix(1);
    while (!s.empty() && space(s.back()))
        s.remove_suffix(1);
    return s;
}

void validate_name(std::string_view name, std::size_t line)
{
    if (name.empty() || digit(name.front()) ||
        !std::all_of(name.begin(), name.end(), [](char c) { return alnum(c) || c == '_'; }))
        fail(line, "invalid macro name '" + std::string(name) + "'");
}

Token token(std::string text, bool trivia = false, bool identifier = false)
{
    return { std::move(text), trivia, identifier, {} };
}

Tokens tokenize(std::string_view text, bool &in_comment, std::size_t line)
{
    Tokens tokens;
    for (std::size_t at = 0; at < text.size();)
    {
        const auto start = at;
        bool trivia = false, identifier = false;
        if (in_comment || text.substr(at, 2) == "/*")
        {
            if (!in_comment)
            {
                in_comment = true;
                at += 2;
            }
            const auto end = text.find("*/", at);
            if (end == std::string_view::npos)
                at = text.size();
            else
            {
                at = end + 2;
                in_comment = false;
            }
            trivia = true;
        }
        else if (text.substr(at, 2) == "//")
        {
            at = text.find('\n', at);
            if (at == std::string_view::npos)
                at = text.size();
            trivia = true;
        }
        else if (space(text[at]))
        {
            while (at < text.size() && space(text[at]))
                ++at;
            trivia = true;
        }
        else if (text[at] == '\'' || text[at] == '"')
        {
            const char quote = text[at++];
            while (at < text.size() && text[at] != quote)
            {
                if (text[at] == '\\')
                    ++at;
                if (at < text.size())
                    ++at;
            }
            if (at == text.size())
                fail(line, "unterminated quoted token");
            ++at;
        }
        else if (alnum(text[at]) || text[at] == '_')
        {
            identifier = !digit(text[at]);
            while (at < text.size() && (alnum(text[at]) || text[at] == '_'))
                ++at;
        }
        else
        {
            ++at;
            // Punctuation may be a UTF-8 scalar in comments/data identifiers.
            while (at < text.size() && (static_cast<unsigned char>(text[at]) & 0xc0) == 0x80)
                ++at;
        }
        auto value = text.substr(start, at - start);
        tokens.push_back(token(std::string(value), trivia, identifier));
        tokens.back().line = line;
        line += std::count(value.begin(), value.end(), '\n');
    }
    return tokens;
}

Tokens tokenize(std::string_view text, std::size_t line)
{
    bool comment = false;
    return tokenize(text, comment, line);
}

std::string render(const Tokens &tokens)
{
    std::string result;
    for (auto &t : tokens)
        result += t.text;
    return result;
}

std::vector<std::string> target_aliases(std::string_view name)
{
    for (auto game : { "FOMT", "MFOMT" })
        for (auto region : { "JP", "US", "EU", "DE" })
            if (!(std::string_view(game) == "MFOMT" &&
                  (std::string_view(region) == "EU" || std::string_view(region) == "DE")) &&
                name == "MARY_" + std::string(game) + "_" + region)
                return { "MARY_" + std::string(game), "REGION_" + std::string(region) };
    return {};
}

void define_macro(std::string_view text, std::size_t line, Macros &macros)
{
    auto tokens = tokenize(text, line);
    if (tokens.empty() || !tokens[0].identifier)
        fail(line, "expected macro name");
    auto name = tokens[0].text;
    validate_name(name, line);
    std::size_t at = 1;
    Macro macro;
    auto is = [&](std::string_view value)
    { return at < tokens.size() && tokens[at].text == value; };
    auto skip = [&]
    {
        while (at < tokens.size() && tokens[at].trivia)
            ++at;
    };
    if (is("("))
    {
        ++at;
        macro.parameters.emplace();
        auto &params = *macro.parameters;
        for (;;)
        {
            skip();
            if (is(")"))
            {
                ++at;
                break;
            }
            if (at == tokens.size() || !tokens[at].identifier)
                fail(line, "expected named macro parameter (variadic macros are unsupported)");
            if (std::find(params.begin(), params.end(), tokens[at].text) != params.end())
                fail(line, "duplicate macro parameter");
            params.push_back(tokens[at++].text);
            skip();
            if (is(")"))
            {
                ++at;
                break;
            }
            if (!is(","))
                fail(line, "expected ',' or ')' after macro parameter");
            ++at;
            skip();
            if (is(")"))
                fail(line, "trailing comma in macro parameters");
        }
    }
    macro.replacement.assign(tokens.begin() + at, tokens.end());
    for (auto &t : macro.replacement)
        if (t.text == "#")
            fail(line, "macro stringification and token pasting are unsupported");
    const auto aliases = target_aliases(name);
    if (!aliases.empty())
        for (const auto &entry : macros)
            if (entry.first != name && !target_aliases(entry.first).empty())
                fail(line, "Mary-C target " + name + " conflicts with " + entry.first);
    macros[name] = std::move(macro);
    for (const auto &alias : aliases)
        macros.try_emplace(alias, Macro{ std::nullopt, { token("1") } });
}

Tokens expand(Tokens tokens, const Macros &macros, std::size_t line, unsigned depth = 0)
{
    if (depth > 128)
        fail(line, "macro argument nesting limit exceeded");
    std::size_t at = 0, expansions = 0;
    while (at < tokens.size())
    {
        auto name = tokens[at].text;
        auto definition = macros.find(name);
        if (definition == macros.end() || !tokens[at].identifier || tokens[at].hidden.count(name))
        {
            ++at;
            continue;
        }
        const auto &macro = definition->second;
        auto end = at + 1;
        std::vector<Tokens> args;
        if (macro.parameters)
        {
            while (end < tokens.size() && tokens[end].trivia)
                ++end;
            if (end == tokens.size() || tokens[end].text != "(")
            {
                ++at;
                continue;
            }
            ++end;
            Tokens argument;
            unsigned nesting = 0;
            for (;;)
            {
                if (end == tokens.size())
                    fail(line, "unterminated macro invocation");
                auto &t = tokens[end];
                if (t.text == ")" && nesting == 0)
                {
                    if (!args.empty() || !macro.parameters->empty() ||
                        std::any_of(
                            argument.begin(), argument.end(), [](auto &v) { return !v.trivia; }))
                        args.push_back(std::move(argument));
                    ++end;
                    break;
                }
                else if (t.text == "," && nesting == 0)
                {
                    args.push_back(std::move(argument));
                    argument.clear();
                }
                else
                {
                    if (t.text == "(")
                        ++nesting;
                    if (t.text == ")")
                        --nesting;
                    argument.push_back(t);
                }
                ++end;
            }
            if (args.size() != macro.parameters->size())
                fail(line, "macro '" + name + "' argument count mismatch");
            for (auto &arg : args)
                arg = expand(std::move(arg), macros, line, depth + 1);
        }
        Tokens replacement;
        for (auto &t : macro.replacement)
        {
            auto param = macro.parameters
                             ? std::find(macro.parameters->begin(), macro.parameters->end(), t.text)
                             : std::vector<std::string>::const_iterator{};
            if (macro.parameters && t.identifier && param != macro.parameters->end())
            {
                auto &arg = args[std::size_t(param - macro.parameters->begin())];
                replacement.insert(replacement.end(), arg.begin(), arg.end());
            }
            else
            {
                replacement.push_back(t);
                replacement.back().line = tokens[at].line;
            }
        }
        auto hidden = tokens[at].hidden;
        hidden.insert(name);
        for (auto &t : replacement)
            t.hidden.insert(hidden.begin(), hidden.end());
        replacement.insert(replacement.begin(), token(" ", true));
        replacement.push_back(token(" ", true));
        tokens.erase(tokens.begin() + at, tokens.begin() + end);
        tokens.insert(tokens.begin() + at, replacement.begin(), replacement.end());
        if (++expansions > 100000 || tokens.size() > 1000000)
            fail(line, "macro expansion limit exceeded");
    }
    return tokens;
}

bool condition(std::string_view text, const Macros &macros, std::size_t line)
{
    auto tokens = tokenize(text, line);
    for (std::size_t at = 0; at < tokens.size(); ++at)
    {
        if (tokens[at].text != "defined")
            continue;
        auto end = at + 1;
        auto skip = [&]
        {
            while (end < tokens.size() && tokens[end].trivia)
                ++end;
        };
        skip();
        bool parenthesized = end < tokens.size() && tokens[end].text == "(";
        if (parenthesized)
            ++end;
        skip();
        if (end == tokens.size() || !tokens[end].identifier)
            fail(line, "expected macro name after defined");
        bool present = macros.count(tokens[end++].text) != 0;
        skip();
        if (parenthesized)
        {
            if (end == tokens.size() || tokens[end].text != ")")
                fail(line, "missing ')' after defined");
            ++end;
        }
        tokens.erase(tokens.begin() + at, tokens.begin() + end);
        tokens.insert(tokens.begin() + at, token(present ? "1" : "0"));
    }
    auto expanded = expand(std::move(tokens), macros, line);
    try
    {
        return evaluate_constant(render(expanded), {}, true) != 0;
    }
    catch (const std::runtime_error &error)
    {
        fail(line, error.what());
    }
}

struct Conditional
{
    std::size_t line;
    bool parent_active, branch_taken, active, saw_else;
};

void directive(std::string_view text,
               std::size_t line,
               Macros &macros,
               std::vector<Conditional> &stack)
{
    text = trim(text);
    auto split = std::find_if(text.begin(), text.end(), space) - text.begin();
    auto name = text.substr(0, std::size_t(split));
    auto args = trim(text.substr(std::size_t(split)));
    bool active = stack.empty() || stack.back().active;
    if (name == "define")
    {
        if (active)
            define_macro(args, line, macros);
    }
    else if (name == "undef")
    {
        if (active)
        {
            validate_name(args, line);
            macros.erase(std::string(args));
        }
    }
    else if (name == "ifdef" || name == "ifndef")
    {
        validate_name(args, line);
        bool take = (macros.count(std::string(args)) != 0) == (name == "ifdef");
        stack.push_back({ line, active, take, active && take, false });
    }
    else if (name == "if")
    {
        bool take = active && condition(args, macros, line);
        stack.push_back({ line, active, take, take, false });
    }
    else if (name == "elif")
    {
        if (stack.empty())
            fail(line, "unexpected #elif");
        auto &c = stack.back();
        if (c.saw_else)
            fail(line, "#elif after #else");
        c.active = c.parent_active && !c.branch_taken && condition(args, macros, line);
        c.branch_taken = c.branch_taken || c.active;
    }
    else if (name == "else")
    {
        if (!args.empty())
            fail(line, "#else does not take arguments");
        if (stack.empty())
            fail(line, "unexpected #else");
        auto &c = stack.back();
        if (c.saw_else)
            fail(line, "duplicate #else");
        c.saw_else = true;
        c.active = c.parent_active && !c.branch_taken;
        c.branch_taken = true;
    }
    else if (name == "endif")
    {
        if (!args.empty())
            fail(line, "#endif does not take arguments");
        if (stack.empty())
            fail(line, "unexpected #endif");
        stack.pop_back();
    }
    else if (name.empty() || active)
        fail(line, "unsupported #" + std::string(name));
}

Macros initial_macros(const Options &options, const Macros &inherited)
{
    auto macros = inherited;
    for (auto &entry : options.defines)
        macros[entry.first] = { std::nullopt, tokenize(entry.second, 0) };
    return macros;
}

std::string_view next_line(std::string_view &source)
{
    auto end = source.find('\n');
    auto length = end == std::string_view::npos ? source.size() : end + 1;
    auto line = source.substr(0, length);
    source.remove_prefix(length);
    return line;
}

std::string_view directive_name(std::string_view text)
{
    text = trim(text);
    const auto split = std::find_if(text.begin(), text.end(), space) - text.begin();
    return text.substr(0, std::size_t(split));
}

class Preprocessing
{
  public:
    Preprocessed result;
    std::vector<fs::path> scanned_includes;

    explicit Preprocessing(const IncludeOptions *options, bool scan = false)
      : options(options), scan(scan)
    {
    }

    void file(std::string_view source, const fs::path &path, std::size_t depth = 0)
    {
        const auto id = file_id(path);
        if (!path.empty())
            active_files.emplace_back(fs::weakly_canonical(path), macro_changes);
        try
        {
            process(source, id, depth);
        }
        catch (const PreprocessError &error)
        {
            if (path.empty())
                throw;
            throw std::runtime_error(path.generic_u8string() + ":" +
                                     std::to_string(error.line) + ": " + error.message);
        }
        if (!path.empty())
            active_files.pop_back();
    }

  private:
    const IncludeOptions *options;
    bool scan;
    bool at_line_start = true, line_has_code = false;
    std::size_t macro_changes = 0;
    std::vector<std::pair<fs::path, std::size_t>> active_files;

    std::size_t file_id(const fs::path &path)
    {
        auto &files = result.locations.files;
        auto found = std::find(files.begin(), files.end(), path);
        if (found != files.end())
            return std::size_t(found - files.begin());
        files.push_back(path);
        return files.size() - 1;
    }

    void append(std::string_view text, std::size_t file, std::size_t line, bool trivia)
    {
        while (!text.empty())
        {
            const auto part = next_line(text);
            if (at_line_start)
            {
                result.locations.lines.push_back({ file, line });
                line_has_code = false;
            }
            if (!trivia && !line_has_code)
            {
                result.locations.lines.back() = { file, line };
                line_has_code = true;
            }
            result.text += part;
            at_line_start = part.back() == '\n';
            ++line;
        }
    }

    void include(std::string_view args, std::size_t file, std::size_t line, std::size_t depth)
    {
        if (!options && !scan)
            fail(line, "unsupported #include");
        auto text = trim(args);
        if (text.size() < 2 || text.front() != '"' || text.back() != '"' ||
            text.substr(1, text.size() - 2).find('"') != std::string_view::npos)
            fail(line, "Mary-C include must use one quoted path");
        auto name = fs::u8path(text.substr(1, text.size() - 2));
        if (name.empty())
            fail(line, "Mary-C include path is empty");
        if (scan)
        {
            scanned_includes.push_back(name);
            return;
        }
        const auto provided = options->provided.find(name.filename());
        fs::path path;
        if (provided != options->provided.end())
            path = provided->second;
        else if (name.is_absolute())
            path = name;
        else
        {
            path = result.locations.files.at(file).parent_path() / name;
            if (!fs::is_regular_file(path))
                for (const auto &directory : options->directories)
                {
                    auto candidate = directory / name;
                    if (fs::is_regular_file(candidate))
                    {
                        path = std::move(candidate);
                        break;
                    }
                }
        }
        if (!fs::is_regular_file(path))
            fail(line, "include not found: " + name.generic_u8string());
        path = path.lexically_normal();
        const auto target = file_id(path), start = result.text.size();
        if (provided == options->provided.end())
        {
            // A guard changes the macro state before a valid recursive include.
            const auto entry = std::make_pair(fs::weakly_canonical(path), macro_changes);
            if (std::find(active_files.begin(), active_files.end(), entry) != active_files.end())
                fail(line, "recursive include: " + name.generic_u8string());
            // A cycle which continually mutates macros must also terminate.
            if (depth == 64)
                fail(line, "include nesting limit exceeded at " + name.generic_u8string());
            try
            {
                this->file(read_text(path), path, depth + 1);
            }
            catch (const std::runtime_error &error)
            {
                throw std::runtime_error(std::string(error.what()) + "\n  included from " +
                                         result.locations.files.at(file).generic_u8string() + ":" +
                                         std::to_string(line));
            }
            if (!at_line_start)
                append("\n", target, 0, true);
        }
        result.includes.push_back({ { file, line }, target, start, result.text.size() });
    }

    void process(std::string_view source, std::size_t file, std::size_t depth)
    {
        auto &macros = result.macros;
        std::vector<Conditional> stack;
        Tokens pending;
        bool comment = false;
        std::size_t line = 0, pending_line = 1;
        auto flush = [&]
        {
            std::size_t previous = pending_line;
            for (auto &item : expand(std::move(pending), macros, pending_line))
            {
                if (item.line)
                    previous = item.line;
                append(item.text, file, previous, item.trivia);
            }
            pending.clear();
        };
        while (!source.empty())
        {
            const auto start_line = ++line;
            std::string logical(next_line(source));
            unsigned continuations = 0;
            while ((logical.size() >= 2 && logical.substr(logical.size() - 2) == "\\\n") ||
                   (logical.size() >= 3 && logical.substr(logical.size() - 3) == "\\\r\n"))
            {
                logical.resize(logical.size() - (logical[logical.size() - 2] == '\r' ? 3 : 2));
                if (source.empty())
                    break;
                logical += next_line(source);
                ++line;
                ++continuations;
            }
            auto tokens = tokenize(logical, comment, start_line);
            bool active = stack.empty() || stack.back().active;
            auto first = std::find_if(tokens.begin(), tokens.end(), [](auto &t) { return !t.trivia; });
            bool is_directive = first != tokens.end() && first->text == "#";
            if (is_directive)
            {
                flush();
                std::string text;
                for (++first; first != tokens.end(); ++first)
                    text += first->trivia ? " " : first->text;
                auto name = directive_name(text);
                if (name == "include")
                {
                    append("\n", file, start_line, true);
                    if (active)
                        include(trim(text).substr(name.size()), file, start_line, depth);
                }
                else
                {
                    directive(text, start_line, macros, stack);
                    if (active && (name == "define" || name == "undef"))
                        ++macro_changes;
                    if (!logical.empty() && logical.back() == '\n')
                        append("\n", file, start_line, true);
                }
            }
            else if (active)
            {
                if (pending.empty())
                    pending_line = start_line;
                pending.insert(pending.end(), tokens.begin(), tokens.end());
            }
            else if (!logical.empty() && logical.back() == '\n')
                append("\n", file, start_line, true);
            for (unsigned i = 0; i < continuations; ++i)
            {
                if (active && !is_directive)
                {
                    pending.push_back(token("\n", true));
                    pending.back().line = start_line + i + 1;
                }
                else
                    append("\n", file, start_line + i + 1, true);
            }
        }
        if (comment)
            fail(line, "unterminated block comment");
        if (!stack.empty())
            fail(stack.back().line, "unterminated conditional block");
        flush();
    }
};

} // namespace

void Options::define(std::string_view definition)
{
    auto eq = definition.find('=');
    auto name = definition.substr(0, eq);
    validate_name(name, 0);
    defines[std::string(name)] =
        eq == std::string_view::npos ? "1" : std::string(definition.substr(eq + 1));
    for (const auto &alias : target_aliases(name))
        defines[alias] = "1";
}

Preprocessed preprocess(std::string_view source, const Options &options, const Macros &inherited)
{
    Preprocessing context(nullptr);
    context.result.macros = initial_macros(options, inherited);
    context.file(source, {});
    return std::move(context.result);
}

Preprocessed preprocess_file(std::string_view source,
                             const fs::path &path,
                             const Options &options,
                             const IncludeOptions &includes,
                             const Macros &inherited)
{
    Preprocessing context(&includes);
    context.result.macros = initial_macros(options, inherited);
    context.file(source, path.lexically_normal());
    return std::move(context.result);
}

SourcePreamble scan_source_preamble(std::string_view source, const Options &options)
{
    Preprocessing context(nullptr, true);
    context.result.macros = initial_macros(options, {});
    context.file(source, {});
    return { std::move(context.result.macros), std::move(context.scanned_includes) };
}

SourceLine SourceLines::at(std::size_t expanded_line) const
{
    if (expanded_line && expanded_line <= lines.size())
        return lines[expanded_line - 1];
    if (expanded_line == lines.size() + 1 && !lines.empty())
        return { lines.back().file, lines.back().line + 1 };
    return {};
}

std::string SourceLines::describe(std::size_t expanded_line) const
{
    auto origin = at(expanded_line);
    if (origin.line && !files.at(origin.file).empty())
        return files.at(origin.file).generic_u8string() + ":" + std::to_string(origin.line);
    return "line " + std::to_string(expanded_line);
}

std::string preprocess_charmap(std::string_view source, const Options &options)
{
    auto macros = initial_macros(options, {});
    std::vector<Conditional> stack;
    std::string output;
    std::size_t line = 0;
    while (!source.empty())
    {
        auto raw = next_line(source);
        if (!raw.empty() && raw.back() == '\n')
        {
            raw.remove_suffix(1);
            if (!raw.empty() && raw.back() == '\r')
                raw.remove_suffix(1);
        }
        auto text = trim(raw);
        ++line;
        if (!text.empty() && text.front() == '#')
        {
            // Ordinary hash comments are part of the established TBL format.
            if (text.substr(0, 3) == "#if" || text.substr(0, 5) == "#elif" || text == "#else" ||
                text.substr(0, 6) == "#endif")
                directive(text.substr(1), line, macros, stack);
        }
        else if (stack.empty() || stack.back().active)
            output += raw;
        if (!source.empty())
            output += '\n';
    }
    if (!stack.empty())
        fail(stack.back().line, "unterminated conditional block");
    return output;
}

} // namespace mary
