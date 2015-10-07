/**
 * Store Game State
 *
 * A State represents the current world and action took to became on this
 * State.
 */

#ifndef _STATE_H_INCLUDED
#define _STATE_H_INCLUDED

/* Possible Actions */
#include <8puzzle/action.h>
#include <8puzzle/coordinate.h>

typedef struct State {
  /* Game Representation */
  unsigned int game[3][3];

  /* Action */
  Action action;

  /* Coordinate of Empty Space */
  Coordinate empty_space;

  /* Parent State */
  struct State *parent;
} State;

/**
 * Display State
 *
 * This will render the keyboard of our current State passed as
 * parameter.
 * 
 * @param s State to be outputed
 */
void print_state(State *s);

/**
 * Generate Possible Sucessors for Current State
 *
 * This method will assign a array of possible Coordinates to lookup, as
 * possible states, and return the number of Coordinates filled on that vector
 * of Coordinates.
 *
 * We have allocated only 4 positions, because this is the max number of
 * coordinates in the best case, when the empty space is in the middle.
 * 
 * @param  s                    Current State to be analyzed
 * @param  possible_coordinates Where to store the possible Coordinates
 * @return                      Amount of possible coordinates
 */
int generate_state_sucessors(State *s, Coordinate *possible_coordinates, Action *actions);

/**
 * Swap the Current Position to Coordinate
 *
 * This will create a new State swapped from the source `empty_space`
 * coordinate to the `destination` Coordinate.
 * 
 * @param  src           Source State
 * @param  destination   Destination to swap the empty space
 * @return               A new State
 */
State *swap_state(State *src, Coordinate destination);

#endif
