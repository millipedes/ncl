#include "include/symbol.h"

const char * ncl_type_to_string(ncl_type type) {
  switch(type) {
    case NCL_STRING:    return "String";
    case NCL_BOOL:      return "Bool";
    case NCL_NUMBER:    return "Number";
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
    case NCL_NUMBER:
      the_symbol.value = to_number(value);
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
  size_t str_len = strnlen(str_value, MAX_STRING_LEN) + 1;
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

symbol_value to_number(const void * value) {
  symbol_value the_symbol_value = {0};
  the_symbol_value.the_number = *(double *)value;
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
  assert_add_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_STRING:
      ret.type = NCL_STRING;
      if(s2.type == NCL_STRING) {
        concat_string(s1.value.the_string, s2.value.the_string, ret.value.the_string);
      } else if(s2.type == NCL_NUMBER) {
        char buf[MAX_QTY_DIGITS] = {0};
        sprintf(buf, "%d", (int)s2.value.the_number);
        concat_string(s1.value.the_string, buf, ret.value.the_string);
      } else {
        fprintf(stderr, "[ADD_SYMBOL]: Unknown Error, Exiting\n");
      }
      break;
    case NCL_NUMBER:
      if(s2.type == NCL_NUMBER) {
        ret.type = NCL_NUMBER;
        ret.value.the_number = s1.value.the_number + s2.value.the_number;
      } else if(s2.type == NCL_STRING) {
        ret.type = NCL_STRING;
        char buf[MAX_QTY_DIGITS] = {0};
        sprintf(buf, "%d", (int)s1.value.the_number);
        concat_string(buf, s2.value.the_string, ret.value.the_string);
      } else {
        fprintf(stderr, "[ADD_SYMBOL]: Unknown Error, Exiting\n");
      }
      break;
    default:
      OPERATOR_NOT_SUPPORTED("ADD_SYMBOL", "Addition")
  }
  return ret;
}

void concat_string(const char * s1, const char * s2, char * ret) {
  size_t s1_len = strnlen(s1, MAX_STRING_LEN);
  size_t s2_len = strnlen(s2, MAX_STRING_LEN);
  strncat(ret, s1, s1_len);
  strncat(ret, s2, s2_len + 1);
}

symbol sub_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_NUMBER;
      ret.value.the_number = s1.value.the_number - s2.value.the_number;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("SUB_SYMBOL", "Subtraction")
  }
  return ret;
}

symbol mult_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_NUMBER;
      ret.value.the_number = s1.value.the_number * s2.value.the_number;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("MULT_SYMBOL", "Multiplication")
  }
  return ret;
}

symbol div_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_NUMBER;
      ret.value.the_number = s1.value.the_number / s2.value.the_number;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("DIV_SYMBOL", "Division")
  }
  return ret;
}

symbol mod_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_NUMBER;
      ret.value.the_number = (int)s1.value.the_number % (int)s2.value.the_number;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("MOD_SYMBOL", "Modulus")
  }
  return ret;
}

symbol less_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_BOOL;
      ret.value.the_bool = s1.value.the_number < s2.value.the_number;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("LESS_SYMBOL", "Less than")
  }
  return ret;
}

symbol great_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_BOOL;
      ret.value.the_bool = s1.value.the_number > s2.value.the_number;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("GREAT_SYMBOL", "Greater than")
  }
  return ret;
}

symbol less_equal_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_BOOL;
      ret.value.the_bool = s1.value.the_number <= s2.value.the_number;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("LESS_EQUAL_SYMBOL", "Less or equal to")
  }
  return ret;
}

symbol great_equal_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_BOOL;
      ret.value.the_bool = s1.value.the_number >= s2.value.the_number;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("GREAT_EQUAL_SYMBOL", "Greater or equal to")
  }
  return ret;
}

symbol eq_equal_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_BOOL;
      ret.value.the_bool = fabs(s1.value.the_number - s2.value.the_number) <= 0.00001;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("EQEQUAL_SYMBOL", "Equal to")
  }
  return ret;
}

symbol land_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_BOOL;
      ret.value.the_bool = s1.value.the_number && s2.value.the_number;
      break;
    case NCL_BOOL:
      ret.type = NCL_BOOL;
      ret.value.the_bool = s1.value.the_bool && s2.value.the_bool;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("LAND_SYMBOL", "Logical And")
  }
  return ret;
}

symbol lor_symbol(symbol s1, symbol s2) {
  symbol ret = {0};
  assert_symbol_type_compatability(s1, s2);
  switch(s1.type) {
    case NCL_NUMBER:
      ret.type = NCL_BOOL;
      ret.value.the_bool = s1.value.the_number || s2.value.the_number;
      break;
    case NCL_BOOL:
      ret.type = NCL_BOOL;
      ret.value.the_bool = s1.value.the_bool || s2.value.the_bool;
      break;
    default:
      OPERATOR_NOT_SUPPORTED("GREAT_EQUAL_SYMBOL", "Logical Or")
  }
  return ret;
}

void assert_add_symbol_type_compatability(symbol s1, symbol s2) {
  if(!number_and_string(s1, s2) && s1.type != s2.type) {
    fprintf(stderr, "Value type `%s` is not compatable with value type `%s`, "
        "Exiting\n", ncl_type_to_string(s1.type), ncl_type_to_string(s2.type));
    exit(1);
  }
}

int number_and_string(symbol s1, symbol s2) {
  return (s1.type == NCL_STRING && s2.type == NCL_NUMBER)
         || (s1.type == NCL_NUMBER && s2.type == NCL_STRING);
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
    case NCL_NUMBER:
      printf("%.2f\n", the_symbol.value.the_number);
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

int symbol_true(symbol the_symbol) {
  switch(the_symbol.type) {
    case NCL_BOOL:
      return the_symbol.value.the_bool;
    case NCL_NUMBER:
      return the_symbol.value.the_number;
    default:
      fprintf(stderr, "[SYMBOL_TRUE]: Unable to determine truth value of type"
          "`%s`, Exiting\n", ncl_type_to_string(the_symbol.type));
      exit(1);
  }
}

int symbol_bound(symbol the_symbol) {
  switch(the_symbol.type) {
    case NCL_NUMBER:
      return the_symbol.value.the_number;
    default:
      fprintf(stderr, "[SYMBOL_BOUND]: Unable to determine bound value of type"
          "`%s`, Exiting\n", ncl_type_to_string(the_symbol.type));
      exit(1);
  }
}

void write_shape_symbol_to_canvas(symbol shape, canvas * the_canvas) {
  switch(shape.type) {
    case NCL_RECTANGLE:
      *the_canvas = draw_rectangle(*the_canvas, shape.value.the_rectangle);
      break;
    case NCL_ELLIPSE:
      *the_canvas = draw_ellipse(*the_canvas, shape.value.the_ellipse);
      break;
    case NCL_LINE:
      *the_canvas = bresenham_line_draw(*the_canvas, shape.value.the_line);
      break;
    default:
      fprintf(stderr, "[WRITE_SHAPE_SYMBOL_TO_CANVAS]: Unable to wrte value of "
          "type `%s` to canvas, Exiting\n", ncl_type_to_string(shape.type));
      exit(1);
  }
}
