#include "parser.tab.h"

extern FILE * yyin;
extern int yylex_destroy();
extern ast head;

int main(void) {
  // token the_token = init_token("Some String", 0);
  // debug_token(the_token);
  // free_token(the_token);
  // symbol_table st = init_symbol_table();
  yyin = fopen("../examples/parser_test.ncl", "r");
  if(!yyin) {
    printf("unable to open input file\n");
    exit(1);
  }
  yyparse();
  // canvas the_canvas = execute(head, st, (canvas){0});
  // write_canvas_png(the_canvas, "first_picture.png");
  // free_canvas(the_canvas);
  // free_symbol_table(st);
  debug_ast(head, 0);
  free_ast(head);
  fclose(yyin);
  yylex_destroy();
  return 0;
}
