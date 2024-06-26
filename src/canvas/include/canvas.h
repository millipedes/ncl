/**
 * @file   canvas.h
 * @brief  This file contains the function definitions for canvas.c.
 * @author Matthew C. Lindeman
 * @date   January 30, 2024
 * @bug    None known
 * @todo   Nothing
 */
#ifndef CAN_H
#define CAN_H

#include <math.h>
#include <png.h>
#include "pixel.h"

#define PPM_HEADER "P3"

#define DEFAULT_CANVAS_WIDTH 1000
#define DEFAULT_CANVAS_HEIGHT 1000

typedef struct CANVAS_PARAMETERS_T {
  pixel color;
  int height;
  int width;
} canvas_parameters;

typedef struct CANVAS_T {
  pixel ** values;
  int height;
  int width;
} canvas;

canvas init_canvas(int height, int width, uint8_t r, uint8_t g, uint8_t b);
canvas set_with_color(canvas the_canvas, const pixel color);
void debug_canvas(canvas the_canvas);
void write_canvas_ppm(canvas the_canvas, const char * file_name);
canvas read_canvas_ppm(const char * file_name);
void write_canvas_png(canvas the_canvas, const char * file_name);
canvas read_canvas_png(const char *file_name);
void free_canvas(canvas the_canvas);

#endif
