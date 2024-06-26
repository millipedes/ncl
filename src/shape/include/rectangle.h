/**
 * @file   rectangle.h
 * @brief  This file contains the function definitions for rectangle.c.
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Make rectangle use draw_line instead of bresenham_line_draw when
 * styles are more concrete.
 */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "line.h"

#define DEFAULT_RECTANGLE_HEIGHT    15
#define DEFAULT_RECTANGLE_WIDTH     15
#define DEFAULT_RECTANGLE_THICKNESS 10

typedef struct RECTANGLE_T {
  coord_2d center;
  pixel color;
  size_t height;
  size_t width;
  int thickness;
} rectangle;

canvas draw_rectangle(canvas the_canvas, rectangle the_rect);
void debug_rectangle(rectangle the_rect);

#endif
