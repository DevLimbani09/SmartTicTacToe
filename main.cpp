/*
 * main fn
 */

#include "Tictactoe.h"

int main()
{

  // get player
  char player;
  while (!isPlayerValid(player))
  {
    cout << "Pick your player (x/o): ";
    cin >> player;
  }

  // get computer
  char computer = findOpponent(player);

  bool state = true;

  while (state)
  {
    playerMove(player);
    // opponentMove(computer);
  }
}
