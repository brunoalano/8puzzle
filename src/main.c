/**
 * 8 Puzzle Game Solver
 *
 * Based on input, we generate a Game State that represents a Root Node
 * and then we apply the BFS algorithm.
 *
 * @author Bruno Alano Medina
 */

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Game */
#include <8puzzle/queue.h>
#include <8puzzle/node.h>
#include <8puzzle/state.h>
#include <8puzzle/action.h>
#include <8puzzle/game.h>

/* Main */
int main(void)
{
  /* Queue containing the States */
  Queue *q = create_queue();

  /* Create Root State */
  State *root_state = malloc(sizeof(State));

  /* Read the State */
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      unsigned int temp;
      scanf("%u", &temp);
      root_state->game[i][j] = temp;
      if (temp == 0)
      {
        root_state->empty_space.line = i;
        root_state->empty_space.column = j;
      }
    }

  /* Create a Node */
  Node *root = malloc(sizeof(Node));
  root->data = root_state;

  /* Check if it's finished */
  if (is_finished(root->data))
  {
    printf("Já está finalizado.\n");
    return 0;
  }

  /* Add State to Queue */
  enqueue(q, root);

  /* Iterate while queue isn't empty */
  while (!is_queue_empty(q))
  {
    /* Get current node */
    State *state = (State *)dequeue(q);

    /* Check if it's correct */
    if (is_finished(state))
    {
      State *parent = state->parent;
      while (parent)
      {
        printf("1\n");
        parent = parent->parent;
      }
      return 0;
    }

    /* Generate possible moves */
    Coordinate *sucessors = malloc(4 * sizeof(Coordinate));
    int amount_of_sucessors = generate_state_sucessors(state, sucessors);
    
    /* For each new possibility of empty space coordinate */
    for (int i = 0; i < amount_of_sucessors; i++)
    {
      /* Create the new state */
      State *new_state = swap_state(state, sucessors[i]);
      new_state->parent = state;
      
      /* Add it to queue */
      Node *new_node = malloc(sizeof(Node));
      new_node->data = new_state;
      enqueue(q, new_node);
    }
  }

  /* Return to operating system */
  return 0;
}
