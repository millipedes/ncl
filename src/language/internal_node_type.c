#include "include/internal_node_type.h"

const char * internal_node_type_to_string(internal_node_type int_node_type) {
  switch(int_node_type) {
    case IN_NULL:                   return "Not Internal";
    case IN_CANVAS_DECLARATION:     return "Canvas Decl";
    case IN_COLOR_DECLARATION:      return "Color Decl";
    case IN_STAR_NEWLINE_STMT:      return "Star Newline Stmt";
    case IN_STATEMENT:              return "Statement";
    case IN_SHAPE_ASSIGNMENT:       return "Shape Assignment";
    case IN_RECTANGLE_DECLARATION:  return "Rectangle Decl";
    case IN_SHAPE:                  return "Shape";
    case IN_POINT_DECLARATION:      return "Point Declaration";
    case IN_PICK_NEWLINE_STMT:      return "Pick Newline Stmt";
    case IN_ELLIPSE_DECLARATION:    return "Ellipse Decl";
    case IN_TO_DECLARATION:         return "To Decl";
    case IN_FROM_DECLARATION:       return "From Decl";
    case IN_LINE_DECLARATION:       return "Line Decl";
    case IN_FOR_LOOP:               return "For Loop";
    case IN_EXPRESSION:             return "Expression";
    case IN_EXPRESSION_ASSIGNMENT:  return "Expression Assignment";
    case IN_IF_STMT:                return "If Stmt";
    case IN_EXPRESSION_LIST:        return "Expression List";
    case IN_HEIGHT_DECLARATION:     return "Height Decl";
    case IN_WIDTH_DECLARATION:      return "Width Decl";
    case IN_RECTANGLE_PARAMETERS:   return "Rectangle Params";
    case IN_ELLIPSE_PARAMETERS:     return "Ellipse Params";
    case IN_LINE_PARAMETERS:        return "Line Params";
    case IN_MAJOR_AXIS_DECLARATION: return "Major Axis Decl";
    case IN_MINOR_AXIS_DECLARATION: return "Minor Axis Decl";
    case IN_THICKNESS_DECLARATION:  return "Thickness Decl";
    case IN_CANVAS_PARAMETERS:      return "Canvas Params";
    case IN_WRITE:                  return "Write";
  }
  return NULL;
}
