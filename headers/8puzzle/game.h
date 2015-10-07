/**
 * Game Implementation
 *
 * This file will produce the implementation of the game, along with the BFS
 * algorithm to solve the 8-Puzzle Problem.
 */

/* Standard Libraries */
#include <stdbool.h>

/* Game Files */
#include <8puzzle/state.h>
#include <8puzzle/node.h>
#include <8puzzle/queue.h>
#include <8puzzle/action.h>

/* Definitions */
#ifndef _GAME_H_INCLUDED
#define _GAME_H_INCLUDED

/**
 * Check if the Game is Finished
 *
 * We check if the current State complains with the finish state model, where
 * it's the goal of our algorithm.
 * 
 * @param  s State to be checked
 * @return   is valid?
 */
bool is_finished(State *s);

#endif
