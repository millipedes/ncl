/**
 * @file   ellipse.h
 * @brief  This file contains the function definitions related to an ellipse.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "canvas/include/canvas.h"
#include "coordinate.h"

#define DEFAULT_ELLIPSE_MAJOR_AXIS 15
#define DEFAULT_ELLIPSE_MINOR_AXIS 15
#define DEFAULT_ELLIPSE_THICKNESS  10

typedef struct ELLIPSE_T {
  coord_2d center;
  pixel color;
  size_t major_axis;
  size_t minor_axis;
  int thickness;
} ellipse;

canvas draw_ellipse(canvas the_canvas, ellipse the_ellipse);
canvas draw_ellipse_points(canvas the_canvas, ellipse the_ellipse, int center_x,
    int center_y, int x, int y);
void debug_ellipse(ellipse the_ellipse);

#endif
