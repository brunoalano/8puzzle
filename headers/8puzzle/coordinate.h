/**
 * Store Coordinate in Matrix
 *
 * The purpose of this structure it's to improve the performance
 * of algorithm since we don't need to find the position of the empty
 * space in our State every time
 */

#ifndef _COORDINATE_H_INCLUDED
#define _COORDINATE_H_INCLUDED

typedef struct Coordinate {
  unsigned int line;
  unsigned int column;
} Coordinate;

#endif
