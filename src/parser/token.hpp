#pragma once

#include <string>

namespace parser
{
    enum token_type {
        // Symbols
        lbrace,rbrace, // {}
        lbracket,rbracket, // []
        lparen,rparen, // ()
        confirm, // :
        assign, // =
        comma,
        math_op, // Math operator
        cond_op, // Conditional Operator
        // Keywords
        entry,
        if_kw,else_kw,
        ret_kw,
        while_kw,
        for_kw,
        namespace_kw,
        import_kw,
        dtype, // any data-type
        // Other
        ident,
        literal,
        unknown,
        eof
    };

    class token
    {
        public:
        std::string value;
        token_type type;
    };
}