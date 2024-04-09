/**
 * @file   line_test.c
 * @brief  This file contains the test for drawing lines, could be improved, not
 * really a good test.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "line_test.h"

/**
 * This function tests drawing a line onto a canvas.
 * @param N/a
 * @return  1
 */
int line_test(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  coord_2d to = {100.0, 500.0};
  coord_2d from = {900.0, 500.0};
  line the_line = {to, from, (pixel){0, 23, 42}, 15};
  the_canvas = bresenham_line_draw(the_canvas, the_line);
  to = (coord_2d){500.0, 100.0};
  from = (coord_2d){500.0, 900.0};
  the_line = (line){to, from, (pixel){0, 23, 42}, 15};
  the_canvas = bresenham_line_draw(the_canvas, the_line);
  to = (coord_2d){100.0, 100.0};
  from = (coord_2d){900.0, 900.0};
  the_line = (line){to, from, (pixel){0, 23, 42}, 15};
  the_canvas = bresenham_line_draw(the_canvas, the_line);
  to = (coord_2d){100.0, 900.0};
  from = (coord_2d){900.0, 100.0};
  the_line = (line){to, from, (pixel){0, 23, 42}, 15};
  the_canvas = bresenham_line_draw(the_canvas, the_line);
  write_canvas_png(the_canvas, "line_test.png");
  free_canvas(the_canvas);
  return 1;
}
