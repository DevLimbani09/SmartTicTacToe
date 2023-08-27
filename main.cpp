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

  bool state = false;

  while (!state)
  {
    playerMove(player);
    state = hasWon();
    playerMove(computer);
    state = hasWon();
    // opponentMove(computer);
  }
}
