%option nounput noinput noyywrap yylineno

%{
#include "parser.tab.h"
#include "language/include/ast.h"

#define IS_UNNECESSARY_TOK(t) ((t == COMMA)        \
                              || (t == LPAR)       \
                              || (t == RPAR)       \
                              || (t == LBRACE)     \
                              || (t == RBRACE)     \
                              || (t == CANVAS)     \
                              || (t == COLOR)      \
                              || (t == RECTANGLE)  \
                              || (t == LINE)       \
                              || (t == FROM)       \
                              || (t == TO)         \
                              || (t == IN)         \
                              || (t == COMMENT)    \
                              || (t == FOR)        \
                              || (t == WRITE)      \
                              || (t == IF)         \
                              || (t == RANGE)      \
                              || (t == THICKNESS)  \
                              || (t == MAJOR_AXIS) \
                              || (t == MINOR_AXIS) \
                              || (t == NEWLINE)    \
                              || (t == HEIGHT)     \
                              || (t == WIDTH)      \
                              || (t == ELLIPSE)    \
                              || (t == POINT))

int allocate_ast(size_t category);
void print_unmatched_quote(char * literal, int line_no);
%}
%%

'(\\.|''|[^'\n])*'        |
\"(\\.|\"\"|[^\"\n])*\"   { return allocate_ast(STRING); }

'(\\.|''|[^'\n])*[\n]     |
\"(\\.|\"\"|[^\"\n])*[\n] { print_unmatched_quote(yytext, yylineno); }

<<EOF>>                   { return allocate_ast(ENDMARKER); }
\\[\n][ \t]*

[\n\v\f\r]+               { return allocate_ast(NEWLINE); }

[ \t]

#.*          { return allocate_ast(COMMENT); }
"color"      { return allocate_ast(COLOR); }
"for"        { return allocate_ast(FOR); }
"height"     { return allocate_ast(HEIGHT); }
"width"      { return allocate_ast(WIDTH); }
"if"         { return allocate_ast(IF); }
"in"         { return allocate_ast(IN); }
"line"       { return allocate_ast(LINE); }
"to"         { return allocate_ast(TO); }
"true"       { return allocate_ast(TRUE); }
"from"       { return allocate_ast(FROM); }
"false"      { return allocate_ast(FALSE); }
"point"      { return allocate_ast(POINT); }
"write"      { return allocate_ast(WRITE); }
"range"      { return allocate_ast(RANGE); }
"minor_axis" { return allocate_ast(MINOR_AXIS); }
"major_axis" { return allocate_ast(MAJOR_AXIS); }
"canvas"     { return allocate_ast(CANVAS); }
"ellipse"    { return allocate_ast(ELLIPSE); }
"rectangle"  { return allocate_ast(RECTANGLE); }
"thickness"  { return allocate_ast(THICKNESS); }

[A-Za-z_][A-Za-z0-9_]*  { return allocate_ast(NAME); }

[0-9_]+                         |
[0-9_]+(e|E)[-+]?[0-9]*         |
"."[0-9]+                       |
"."[0-9]+(e|E)[-+]?[0-9]*       |
[0-9]+"."[0-9]+                 |
[0-9]+"."[0-9]+(e|E)[-+]?[0-9]* { return allocate_ast(NUMBER); }

"("  { return allocate_ast(LPAR); }
")"  { return allocate_ast(RPAR); }
","  { return allocate_ast(COMMA); }
"+"  { return allocate_ast(PLUS); }
"-"  { return allocate_ast(MINUS); }
"*"  { return allocate_ast(STAR); }
"/"  { return allocate_ast(SLASH); }
"||" { return allocate_ast(LOR); }
"&&" { return allocate_ast(LAND); }
"<"  { return allocate_ast(LESS); }
">"  { return allocate_ast(GREATER); }
"="  { return allocate_ast(EQUAL); }
"%"  { return allocate_ast(PERCENT); }
"{"  { return allocate_ast(LBRACE); }
"}"  { return allocate_ast(RBRACE); }
"==" { return allocate_ast(EQEQUAL); }
"!=" { return allocate_ast(NOTEQUAL); }
"<=" { return allocate_ast(LESSEQUAL); }
">=" { return allocate_ast(GREATEREQUAL); }
%%

int allocate_ast(size_t category) {
  if(!IS_UNNECESSARY_TOK(category))
    if(category != STRING) {
      yylval.the_ast = init_ast(init_token(yytext, category), category);
    } else { // yytext has the "\""s
      char * buf = NULL;
      size_t len = strnlen(yytext, 1024);
      buf = calloc(len, sizeof(char));
      strncat(buf, yytext + 1, len - 2); // don't want the close " or \0
      buf[len - 1] = '\0';               // play nice with str* funcs
      yylval.the_ast = init_ast(init_token(buf, category), category);
      free(buf);
    }
  else
    yylval.the_ast = (ast){0};
  return category;
}

void print_unmatched_quote(char * literal, int line_no) {
  fprintf(stderr, "[LEXER]: Unmatched quote: `%s` on line %d\n", literal,
    line_no);
}
