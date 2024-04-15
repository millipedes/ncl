#include "language/include/execute.h"

extern FILE * yyin;
extern int yylex_destroy();
extern ast head;

int main(void) {
  // token the_token = init_token("Some String", 0);
  // debug_token(the_token);
  // free_token(the_token);
  symbol_table st = (symbol_table){0};
  yyin = fopen("../docs/example_001/hello_canvas.ncl", "r");
  if(!yyin) {
    printf("unable to open input file\n");
    exit(1);
  }
  yyparse();
  canvas the_canvas = execute_canvas_declaration(head, st);
  write_canvas_png(the_canvas, "first_picture.png");
  free_canvas(the_canvas);
  free_symbol_table(st);
  // debug_ast(head, 0);
  free_ast(head);
  fclose(yyin);
  yylex_destroy();

  // char * a = "test 1";
  // int b = 1;
  // double c = 2.0;
  // int d = 2;
  // pixel e = (pixel){0, 23, 42};
  // rectangle f = (rectangle){(coord_2d){1.0, 2.0}, (pixel){0, 23, 42}, 15, 15, 15};
  // ellipse g = (ellipse){(coord_2d){1.0, 2.0}, (pixel){0, 23, 42}, 15, 15, 15};
  // symbol_ll the_symbol_ll = init_symbol_ll("a", a, NCL_STRING);
  // the_symbol_ll = append_symbol_ll(the_symbol_ll, init_symbol_ll("b", &b, NCL_BOOL));
  // the_symbol_ll = append_symbol_ll(the_symbol_ll, init_symbol_ll("c", &c, NCL_DOUBLE));
  // the_symbol_ll = append_symbol_ll(the_symbol_ll, init_symbol_ll("d", &d, NCL_INT));
  // the_symbol_ll = append_symbol_ll(the_symbol_ll, init_symbol_ll("e", &e, NCL_COLOR));
  // the_symbol_ll = append_symbol_ll(the_symbol_ll, init_symbol_ll("f", &f, NCL_RECTANGLE));
  // the_symbol_ll = append_symbol_ll(the_symbol_ll, init_symbol_ll("g", &g, NCL_ELLIPSE));
  // debug_symbol_ll(the_symbol_ll);
  // free_symbol_ll(the_symbol_ll);

  // symbol_table map = {0};
  // map = add_entry(map, "a", a, NCL_STRING);
  // map = add_entry(map, "b", &b, NCL_BOOL);
  // map = add_entry(map, "c", &c, NCL_DOUBLE);
  // map = add_entry(map, "d", &d, NCL_INT);
  // map = add_entry(map, "e", &e, NCL_COLOR);
  // map = add_entry(map, "f", &f, NCL_RECTANGLE);
  // map = add_entry(map, "g", &g, NCL_ELLIPSE);
  // debug_symbol_table(map);
  // free_symbol_table(map);

  return 0;
}
