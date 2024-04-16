#ifndef POINT_H
#define POINT_H

#include <stdio.h>

#define DEFAULT_X 0.0
#define DEFAULT_Y 0.0


typedef struct COORD2D_T {
  double x;
  double y;
} coord_2d;

void debug_coord_2d(coord_2d the_coord_2d);

#endif
