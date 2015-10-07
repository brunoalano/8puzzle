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
#include <8puzzle/game.h>

bool is_finished(State *s)
{
  if (s->game[0][0] != 1) return false;
  if (s->game[0][1] != 2) return false;
  if (s->game[0][2] != 3) return false;
  if (s->game[1][0] != 8) return false;
  if (s->game[1][2] != 4) return false;
  if (s->game[2][0] != 7) return false;
  if (s->game[2][1] != 6) return false;
  if (s->game[2][2] != 5) return false;
  return true;
}
