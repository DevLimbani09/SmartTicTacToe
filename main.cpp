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

  // get opponent
  char opponent = findOpponent(player);

  bool state = false;

  if (player == PLAYER_1)
  {
    while (!state)
    {
      playerMove(player);
      state = hasWon();
      playerMove(opponent);
      state = hasWon();
      // opponentMove(opponent);
    }
  }
  else
  {
    while (!state)
    {
      playerMove(opponent);
      state = hasWon();
      playerMove(player);
      state = hasWon();
      // opponentMove(opponent);
    }
  }
}
