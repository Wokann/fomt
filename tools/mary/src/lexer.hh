#ifndef MARY_LEXER_HH
#define MARY_LEXER_HH

#include "charmap.hh"
#include <string>
#include <string_view>
#include <vector>

namespace mary
{

enum class TokenKind
{
    Identifier,
    Integer,
    String,
    Punctuation,
    End
};
struct Token
{
    TokenKind kind;
    std::string text;
    Integer integer = 0;
    Bytes bytes;
    std::size_t line = 1, column = 1;
};

std::vector<Token> lex(std::string_view source,
                       const Charmap *charmap = nullptr,
                       bool legacy_strings = false);

class Tokens
{
  public:
    explicit Tokens(std::vector<Token> input)
      : input(std::move(input))
    {
    }
    const Token &peek(std::size_t lookahead = 0) const;
    bool end() const
    {
        return peek().kind == TokenKind::End;
    }
    bool is(std::string_view text) const;
    bool eat(std::string_view text);
    void require(std::string_view text);
    Token take();
    std::string identifier();
    Integer integer();
    [[noreturn]] void error(const std::string &message) const;
    std::size_t position() const
    {
        return at;
    }
    void position(std::size_t value)
    {
        at = value;
    }

  private:
    std::vector<Token> input;
    std::size_t at = 0;
};

} // namespace mary
#endif
