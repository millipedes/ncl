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
           | shape_assignment
           | if_stmt
           | for_loop
           | write_declaration

write_declaration -> WRITE LPAR NAME RPAR
                   | WRITE LPAR shape RPAR

for_loop -> FOR NAME IN RANGE LPAR expression RPAR LBRACE star_NEWLINE_stmt RBRACE
          | FOR NAME IN RANGE LPAR expression COMMA expression RPAR LBRACE star_NEWLINE_stmt RBRACE


if_stmt -> IF LPAR expression RPAR LBRACE star_NEWLINE_stmt RBRACE

expression_assignement -> NAME EQUAL expression

shape_assignement -> NAME EQUAL shape

canvas_parameters -> canvas_parameters COMMA canvas_parameter
                   | canvas_parameter

canvas_parameter -> height_declaration
                  | width_declaration
                  | color_declaration

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

shape -> line_declaration
       | ellipse_decoration
       | rectangle_delcaration
       | point_declaration
       | color_declaration
       | NAME

line_declaration -> LINE LPAR line_parameters RPAR
                  | LINE LPAR RPAR

line_parameters -> line_parameters COMMA line_parameter
                 | line_parameter

line_parameter -> color_declaration
                | thickness_declartaion
                | from_declaration
                | to_declaration

ellipse_decoration -> ELLIPSE LPAR ellipse_parameters RPAR
                    | ELLIPSE LPAR RPAR

ellipse_parameters -> ellipse_parameters ellipse_parameter
                    | ellipse_parameter

ellipse_parameter -> color_declaration
                   | point_declaration
                   | major_axis_declartion
                   | minor_axis_declartion
                   | thickness_declaration

rectangle_delcaration -> RECTANGLE LPAR rectangle_parameters RPAR
                       | RECTANGLE LPAR RPAR

rectangle_parameters -> rectangle_parameters COMMA rectangle_parameter
                      | rectangle_parameter

rectangle_parameter -> color_declaration
                     | point_declaration
                     | height_declaration
                     | width_declaration
                     | thickness_declaration

line_declaration -> LINE LPAR from_declaration COMMA to_declaration RPAR
from_declaration -> FROM LPAR shape RPAR
to_declaration -> TO LPAR shape RPAR

point_declaration -> POINT LPAR expression COMMA expression RPAR

color_declaration -> COLOR LPAR expression COMMA expression COMMA expression RPAR

width_declaration -> WIDTH LPAR expression RPAR
height_declaration -> HEIGHT LPAR expression RPAR
thickness_declaration -> THICKNESS LPAR expression RPAR

IN           -> in
RANGE        -> range
FOR          -> for
IF           -> if
CANVAS       -> canvas
ELLIPSE      -> ellipse
RECTANGLE    -> rectangle
POINT        -> point
TO           -> to
FROM         -> from
HEIGHT       -> height
WIDTH        -> width
THICKNESS    -> thickness
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
