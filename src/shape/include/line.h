/**
 * @file   line.h.
 * @brief  This file contains the function definitions for line.c.
 * @author Matthew C. Lindeman
 * @date   July 23, 2023
 * @bug    None known
 * @todo   Write the dotten line style implementation.
 */
#ifndef LINE_H
#define LINE_H

#include "coordinate.h"
#include "canvas/include/canvas.h"

#define DEFAULT_LINE_THICKNESS 10

typedef struct LINE_T {
  coord_2d to;
  coord_2d from;
  pixel color;
  int thickness;
} line;

void debug_line(line the_line);
canvas bresenham_line_draw(canvas the_canvas, line the_line);

#endif
