#ifndef SYMBOL_H
#define SYMBOL_H

#include <string.h>

#include "shape/include/ellipse.h"
#include "shape/include/rectangle.h"

#define MAX_SYMBOL_BYTES 1024

#define OPERATOR_NOT_SUPPORTED(where, op)                          \
  fprintf(stderr, "[##where##]: ##op## operator not supported"     \
      " for type: `%s`, Exiting.\n", ncl_type_to_string(s1.type)); \
  exit(1);

typedef enum {
  NCL_STRING = 1,
  NCL_BOOL,
  NCL_DOUBLE,
  NCL_INT,
  NCL_COLOR,
  NCL_RECTANGLE,
  NCL_ELLIPSE,
} ncl_type;

const char * ncl_type_to_string(ncl_type type);

typedef union {
  char * the_string;
  int the_bool;
  double the_double;
  int the_integer;
  pixel the_color;
  rectangle the_rectangle;
  ellipse the_ellipse;
} symbol_value;

typedef struct SYMBOL_T {
  symbol_value value;
  ncl_type type;
} symbol;

// Conversion from stram
symbol init_symbol(const void * value, ncl_type type);
symbol_value to_string(const void * value);
symbol_value to_bool(const void * value);
symbol_value to_double(const void * value);
symbol_value to_int(const void * value);
symbol_value to_color(const void * value);
symbol_value to_rectangle(const void * value);
symbol_value to_ellipse(const void * value);

// Operators
symbol add_symbol(symbol s1, symbol s2);
symbol sub_symbol(symbol s1, symbol s2);
symbol mult_symbol(symbol s1, symbol s2);
symbol div_symbol(symbol s1, symbol s2);
symbol mod_symbol(symbol s1, symbol s2);
symbol less_symbol(symbol s1, symbol s2);
symbol great_symbol(symbol s1, symbol s2);
symbol less_equal_symbol(symbol s1, symbol s2);
symbol great_equal_symbol(symbol s1, symbol s2);

void assert_symbol_type_compatability(symbol s1, symbol s2);
void debug_symbol(symbol the_symbol);
void free_symbol(symbol the_symbol);

#endif
