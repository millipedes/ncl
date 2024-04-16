#include "include/symbol.h"

const char * ncl_type_to_string(ncl_type type) {
  switch(type) {
    case NCL_STRING:    return "String";
    case NCL_BOOL:      return "Bool";
    case NCL_DOUBLE:    return "Double";
    case NCL_INT:       return "Int";
    case NCL_POINT:     return "Point";
    case NCL_COLOR:     return "Color";
    case NCL_RECTANGLE: return "Rectangle";
    case NCL_ELLIPSE:   return "Ellipse";
    case NCL_LINE:      return "Line";
  }
  return NULL;
}

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
    case NCL_POINT:
      the_symbol.value = to_point(value);
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
    case NCL_LINE:
      the_symbol.value = to_line(value);
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

symbol_value to_point(const void * value) {
  symbol_value the_symbol_value = {0};
  const coord_2d color_value = *(const coord_2d *)value;
  double x = color_value.x;
  double y = color_value.y;
  the_symbol_value.the_point = (coord_2d){x, y};
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

symbol_value to_line(const void * value) {
  symbol_value the_symbol_value = {0};
  const line line_value = *(const line *)value;
  coord_2d to = (coord_2d){line_value.to.x, line_value.to.y};
  coord_2d from = (coord_2d){line_value.from.x, line_value.from.y};
  pixel color = (pixel){line_value.color.r, line_value.color.g, line_value.color.b};
  size_t thickness = line_value.thickness;
  the_symbol_value.the_line = (line){
    to,
    from,
    color,
    thickness
  };
  return the_symbol_value;
}

symbol add_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_STRING:
      symbol concat_string = {0};
      size_t s1_len = strnlen(s1.value.the_string, MAX_SYMBOL_BYTES);
      size_t s2_len = strnlen(s2.value.the_string, MAX_SYMBOL_BYTES);
      size_t concat_string_len = s1_len + s2_len + 1;
      concat_string.value.the_string = calloc(concat_string_len, sizeof(char));
      strncat(concat_string.value.the_string, s1.value.the_string, s1_len);
      strncat(concat_string.value.the_string + s1_len, s2.value.the_string, s2_len + 1);
      break;
    case NCL_DOUBLE:
      ret.type = NCL_DOUBLE;
      ret.value.the_double = s1.value.the_double + s2.value.the_double;
      break;
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer + s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(ADD_SYMBOL, Addition)
  }
  return ret;
}

symbol sub_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_DOUBLE:
      ret.type = NCL_DOUBLE;
      ret.value.the_double = s1.value.the_double - s2.value.the_double;
      break;
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer - s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(SUB_SYMBOL, Subtraction)
  }
  return ret;
}

symbol mult_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_DOUBLE:
      ret.type = NCL_DOUBLE;
      ret.value.the_double = s1.value.the_double * s2.value.the_double;
      break;
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer * s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(MULT_SYMBOL, Multiplication)
  }
  return ret;
}

symbol div_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_DOUBLE:
      ret.type = NCL_DOUBLE;
      ret.value.the_double = s1.value.the_double / s2.value.the_double;
      break;
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer / s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(DIV_SYMBOL, Division)
  }
  return ret;
}

symbol mod_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer % s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(MOD_SYMBOL, Modulus)
  }
  return ret;
}

symbol less_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_DOUBLE:
      ret.type = NCL_DOUBLE;
      ret.value.the_double = s1.value.the_double < s2.value.the_double;
      break;
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer < s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(LESS_SYMBOL, Less than)
  }
  return ret;
}

symbol great_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_DOUBLE:
      ret.type = NCL_DOUBLE;
      ret.value.the_double = s1.value.the_double > s2.value.the_double;
      break;
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer > s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(GREAT_SYMBOL, Greater than)
  }
  return ret;
}

symbol less_equal_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_DOUBLE:
      ret.type = NCL_DOUBLE;
      ret.value.the_double = s1.value.the_double <= s2.value.the_double;
      break;
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer <= s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(LESS_EQUAL_SYMBOL, Less or equal to)
  }
  return ret;
}

symbol great_equal_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_DOUBLE:
      ret.type = NCL_DOUBLE;
      ret.value.the_double = s1.value.the_double >= s2.value.the_double;
      break;
    case NCL_INT:
      ret.type = NCL_INT;
      ret.value.the_integer = s1.value.the_integer >= s2.value.the_integer;
      break;
    default:
      OPERATOR_NOT_SUPPORTED(GREAT_EQUAL_SYMBOL, Greater or equal to)
  }
  return ret;
}

void assert_symbol_type_compatability(symbol s1, symbol s2) {
  if(s1.type != s2.type) {
    fprintf(stderr, "Value type `%s` is not compatable with value type `%s`, "
        "Exiting\n", ncl_type_to_string(s1.type), ncl_type_to_string(s2.type));
    exit(1);
  }
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
      printf("%.2f\n", the_symbol.value.the_double);
      break;
    case NCL_INT:
      printf("%d\n", the_symbol.value.the_integer);
      break;
    case NCL_POINT:
      debug_coord_2d(the_symbol.value.the_point);
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
    case NCL_LINE:
      debug_line(the_symbol.value.the_line);
      break;
  }
}

void free_symbol(symbol the_symbol) {
  if(the_symbol.type == NCL_STRING)
    if(the_symbol.value.the_string)
      free(the_symbol.value.the_string);
}
