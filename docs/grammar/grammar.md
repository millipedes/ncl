The implemented grammar is as follows:
```
program -> canvas_declaration LBRACE star_NEWLINE_stmt RBRACE

canvas_declaration -> CANVAS LPAR canvas_parameters RPAR
                    | CANVAS LPAR RPAR

star_NEWLINE_stmt -> pick_NEWLINE_stmt star_NEWLINE_stmt
                   | NEWLINE

pick_NEWLINE_stmt -> statement
                   | NEWLINE

statement -> expression_assignement

expression_assignement -> NAME EQUAL expression

canvas_parameters -> canvas_parameters COMMA canvas_parameter
                   | canvas_parameter

canvas_parameter -> height_declaration
                  | width_declaration
                  | color_declaration

height_declaration -> HEIGHT LPAR expression RPAR

width_declaration -> WIDTH LPAR expression RPAR

color_declaration -> COLOR LPAR expression COMMA expression COMMA expression RPAR

expression -> DOUBLE
            | INTEGER
            | NAME
            | STRING
            | TRUE
            | FALSE
            | expression PLUS expression
            | expression MINUS expression
            | expression STAR expression
            | expression SLASH expression
            | expression PERCENT expression
            | expression LESS expression
            | expression GREATER expression
            | expression LESSEQUAL expression
            | expression GREATEREQUAL expression

CANVAS       -> canvas
HEIGHT       -> height
WIDTH        -> width
COLOR        -> color
LPAR         -> (
RPAR         -> )
LBRACE       -> {
RBRACE       -> }
COMMA        -> ,
PLUS         -> +
MINUS        -> -
STAR         -> *
SLASH        -> /
PERCENT      -> %
LESS         -> <
GREATER      -> >
LESSEQUAL    -> <=
GREATEREQUAL -> >=
NEWLINE      -> '\n'
EQUAL        -> =
name         -> (A-Za-z_)+(A-Za-z0-9_)*
```
