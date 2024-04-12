#ifndef SYMBOL_H
#define SYMBOL_H

#include <string.h>

#include "shape/include/ellipse.h"
#include "shape/include/rectangle.h"

#define MAX_SYMBOL_BYTES 1024

typedef enum {
  NCL_STRING = 1,
  NCL_BOOL,
  NCL_DOUBLE,
  NCL_INT,
  NCL_COLOR,
  NCL_RECTANGLE,
  NCL_ELLIPSE,
} ncl_type;

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

symbol init_symbol(const void * value, ncl_type type);
symbol_value to_string(const void * value);
symbol_value to_bool(const void * value);
symbol_value to_double(const void * value);
symbol_value to_int(const void * value);
symbol_value to_color(const void * value);
symbol_value to_rectangle(const void * value);
symbol_value to_ellipse(const void * value);
void debug_symbol(symbol the_symbol);
void free_symbol(symbol the_symbol);

#endif
