/**
 * @file   rectangle.c
 * @brief  This file contains the functions for writing a rectangle.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Make rectangle use draw_line instead of bresenham_line_draw when
 * styles are more concrete.
 */
#include "include/rectangle.h"

/**
 * This function writes a rectangle to a canvas.
 * @param  the_canvas - The canvas for the rectangle to be drawn onto.
 * @param    the_rect - The rectangle which will be drawn onto the cavas.
 * @return the_canvas - The canvas with the rectangle drawn onto it.
 */
canvas draw_rectangle(canvas the_canvas, rectangle the_rect) {
  int half_width = the_rect.width / 2;
  int half_height = the_rect.height / 2;
  int x1 = the_rect.center.x - half_width;
  int y1 = the_rect.center.y - half_height;
  int x2 = the_rect.center.x + half_width;
  int y2 = the_rect.center.y + half_height;

  // Draw the four sides of the rectangle
  bresenham_line_draw(the_canvas, (line){
      (coord_2d){x1, y1}, (coord_2d){x2, y1}, the_rect.color, the_rect.thickness});
  bresenham_line_draw(the_canvas, (line){
      (coord_2d){x2, y1}, (coord_2d){x2, y2}, the_rect.color, the_rect.thickness});
  bresenham_line_draw(the_canvas, (line){
      (coord_2d){x2, y2}, (coord_2d){x1, y2}, the_rect.color, the_rect.thickness});
  bresenham_line_draw(the_canvas, (line){
      (coord_2d){x1, y2}, (coord_2d){x1, y1}, the_rect.color, the_rect.thickness});

  return the_canvas;
}

void debug_rectangle(rectangle the_rect) {
  printf("[RECTANGLE]: Height: %ld, Width: %ld, Thickness: %d, ",
      the_rect.height, the_rect.width, the_rect.thickness);
  printf("Center: (%f, %f), ", the_rect.center.x, the_rect.center.y);
  debug_pixel(the_rect.color);
}

