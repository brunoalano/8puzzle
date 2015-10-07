/**
 * Store Game State
 *
 * A State represents the current world and action took to became on this
 * State.
 */

/* Standard Library for IO */
#include <stdio.h>
#include <stdlib.h>

/* Game State */
#include <8puzzle/state.h>
#include <8puzzle/action.h>

void print_state(State *s)
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
      printf("%u ", s->game[i][j]);
    printf("\n");
  }
}

int generate_state_sucessors(State *s, Coordinate *possible_coordinates, Action *actions)
{
  /* Relative places to move */
  int deltas[4][3] = { {-1, 0, DOWN}, {0, -1, LEFT}, {0, 1, RIGHT}, {1, 0, UP} };

  /* Amount of Coordinates that are valid */
  int count = 0;

  /* For each possible delta, check it */
  for (int i = 0; i < 4; i++)
  {
    int *row = deltas[i];
    int nrow = s->empty_space.line + row[0];
    int ncol = s->empty_space.column + row[1];

    if (nrow >= 0 && nrow < 3 && ncol >= 0 && ncol < 3)
    {
      /* Check for opposites */
      if ((s->action == LEFT && row[2] == RIGHT) || (s->action == RIGHT && row[2] == LEFT) || (s->action == UP && row[2] == DOWN) || (s->action == DOWN && row[2] == UP)) 
      {
        continue; /* Skip */
      }
      else {
        possible_coordinates[count].line = nrow;
        possible_coordinates[count].column = ncol;
        actions[count] = row[2];
        count++;
      }
    }
  }

  /* Amount of valid deltas */
  return count;
}

State *swap_state(State *src, Coordinate destination)
{
  /* Create a new State */
  State *new_state = malloc(sizeof(State));

  /* Copy source to new state */
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      new_state->game[i][j] = src->game[i][j];

  /* Swap */
  new_state->game[destination.line][destination.column] = 0;
  new_state->game[src->empty_space.line][src->empty_space.column] = src->game[destination.line][destination.column];
  new_state->empty_space.line = destination.line;
  new_state->empty_space.column = destination.column;
  return new_state;
}
