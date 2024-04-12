#include "include/symbol.h"

symbol init_symbol(const void * value, ncl_type type) {
  symbol the_symbol = {0};
  the_symbol.type = type;
  switch(type) {
    case NCL_STRING:
      the_symbol.value = to_string(value);
      break;
    case NCL_BOOL:
      the_symbol.value = to_bool(value);
      break;
    case NCL_DOUBLE:
      the_symbol.value = to_double(value);
      break;
    case NCL_INT:
      the_symbol.value = to_int(value);
      break;
    case NCL_COLOR:
      the_symbol.value = to_color(value);
      break;
    case NCL_RECTANGLE:
      the_symbol.value = to_rectangle(value);
      break;
    case NCL_ELLIPSE:
      the_symbol.value = to_ellipse(value);
      break;
  }
  return the_symbol;
}

symbol_value to_string(const void * value) {
  symbol_value the_symbol_value = {0};
  const char * str_value = (const char *)value;
  size_t str_len = strnlen(str_value, MAX_SYMBOL_BYTES) + 1;
  the_symbol_value.the_string = calloc(str_len, sizeof(char));
  strncpy(the_symbol_value.the_string, value, str_len);
  return the_symbol_value;
}

symbol_value to_bool(const void * value) {
  symbol_value the_symbol_value = {0};
  switch(*(int *)value) {
    case 0:
      the_symbol_value.the_bool = 0;
      return the_symbol_value;
    case 1:
      the_symbol_value.the_bool = 1;
      return the_symbol_value;
    default:
      fprintf(stderr, "[TO_BOOL]: something went wrong, exiting\n");
      exit(1);
  }
}

symbol_value to_double(const void * value) {
  symbol_value the_symbol_value = {0};
  the_symbol_value.the_double = *(double *)value;
  return the_symbol_value;
}

symbol_value to_int(const void * value) {
  symbol_value the_symbol_value = {0};
  the_symbol_value.the_integer = *(int *)value;
  return the_symbol_value;
}

symbol_value to_color(const void * value) {
  symbol_value the_symbol_value = {0};
  const pixel color_value = *(const pixel *)value;
  uint8_t r = color_value.r;
  uint8_t g = color_value.g;
  uint8_t b = color_value.b;
  the_symbol_value.the_color = (pixel){r, g, b};
  return the_symbol_value;
}

symbol_value to_rectangle(const void * value) {
  symbol_value the_symbol_value = {0};
  const rectangle rectangle_value = *(const rectangle *)value;
  coord_2d center = (coord_2d){rectangle_value.center.x, rectangle_value.center.y};
  pixel color = (pixel){rectangle_value.color.r, rectangle_value.color.g, rectangle_value.color.b};
  size_t height = rectangle_value.height;
  size_t width = rectangle_value.width;
  int thickness = rectangle_value.thickness;
  the_symbol_value.the_rectangle = (rectangle){
    center,
    color,
    height,
    width,
    thickness
  };
  return the_symbol_value;
}

symbol_value to_ellipse(const void * value) {
  symbol_value the_symbol_value = {0};
  const ellipse ellipse_value = *(const ellipse *)value;
  coord_2d center = (coord_2d){ellipse_value.center.x, ellipse_value.center.y};
  pixel color = (pixel){ellipse_value.color.r, ellipse_value.color.g, ellipse_value.color.b};
  size_t major_axis = ellipse_value.major_axis;
  size_t minor_axis = ellipse_value.minor_axis;
  int thickness = ellipse_value.thickness;
  the_symbol_value.the_ellipse = (ellipse){
    center,
    color,
    major_axis,
    minor_axis,
    thickness
  };
  return the_symbol_value;
}

void debug_symbol(symbol the_symbol) {
  switch(the_symbol.type) {
    case NCL_STRING:
      printf("%s\n", the_symbol.value.the_string);
      break;
    case NCL_BOOL:
      printf("%s\n", the_symbol.value.the_bool ? "true" : "false");
      break;
    case NCL_DOUBLE:
      printf("%f\n", the_symbol.value.the_double);
      break;
    case NCL_INT:
      printf("%d\n", the_symbol.value.the_integer);
      break;
    case NCL_COLOR:
      debug_pixel(the_symbol.value.the_color);
      break;
    case NCL_RECTANGLE:
      debug_rectangle(the_symbol.value.the_rectangle);
      break;
    case NCL_ELLIPSE:
      debug_ellipse(the_symbol.value.the_ellipse);
      break;
  }
}

void free_symbol(symbol the_symbol) {
  if(the_symbol.type == NCL_STRING)
    if(the_symbol.value.the_string)
      free(the_symbol.value.the_string);
}
