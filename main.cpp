/*
 * main fn
 */

#include "Tictactoe.h"

int main()
{

  srand(time(0));

  // get player
  char player;
  while (!isPlayerValid(player))
  {
    cout << "Pick your player (x/o): ";
    cin >> player;
  }

  // get opponent
  char opponent = findOpponent(player);

  bool state = false;

  // main game loop
  while (!isFull())
  {

    if (player == PLAYER_1)
    {
      while (!state)
      {
        playerMove(player);
        state = hasWon();
        // playerMove(opponent);
        computerMove(opponent);
        state = hasWon();
      }
    }
    else
    {
      while (!state)
      {
        // playerMove(opponent);
        computerMove(opponent);
        state = hasWon();
        playerMove(player);
        state = hasWon();
      }
    }
  }
}
