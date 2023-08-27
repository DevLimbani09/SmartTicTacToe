/*
 * used to define fn/class
 */

#include "Tictactoe.h"

char board[ROWS][COLS] = {{' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '}};

int occupied[3][3] = {0};

char toAlpha(int n) { return 'A' + n; }

int toInt(char c) { return c - 'A'; }

void printBoard()
{
  cout << endl;
  cout << "   1   2   3 " << endl;
  for (int i = 0; i < ROWS; i++)
  {

    if (i == 1 || i == 2)
    {
      cout << "  -----------" << endl;
    }

    cout << toAlpha(i) << "  ";

    for (int j = 0; j < COLS; j++)
    {
      cout << board[i][j];
      if (j == 0 || j == 1)
      {
        cout << " | ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void setBoard(char c)
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      setPosition(i, j, c);
    }
  }
}

bool setPosition(int r, int c, char p)
{
  if (occupied[r][c] == 0 && isMoveValid(r, c))
  {
    board[r][c] = p;
    occupied[r][c] = 1;
    return true;
  }
  cout << "Place not empty." << endl;
  return false;
}

char findOpponent(char player)
{
  if (player == PLAYER_1)
  {
    return PLAYER_2;
  }
  return PLAYER_1;
}

void calculateMove(int &r, int &c, char r_move, int c_move)
{
  if (r_move >= 'a' && r_move <= 'z')
  {
    r_move -= 32;
  }

  r = toInt(r_move);
  c = c_move - 1;
}

void playerMove(char player)
{
  char r_move;
  int c_move;
  int move_row, move_col;

  printBoard();

  cout << "Enter your move: ";
  cin >> r_move;
  cin >> c_move;
  calculateMove(move_row, move_col, r_move, c_move);
  // cout << "Calculated move: " << move_row << " " << move_col << endl;

  if (!setPosition(move_row, move_col, player))
  {
    playerMove(player);
  }
}

bool isPlayerValid(char player)
{
  return (player == PLAYER_1 || player == PLAYER_2);
}

bool isMoveValid(int r, int c)
{
  return ((r >= 0 && r < 3) && (c >= 0 && c < 3));
}

bool hasWon()
{
  // check rows
  for (int row = 0; row < ROWS; row++)
  {
    if (board[row][0] == board[row][1] == board[row][2] && board[row][0] != ' ')
    {
      printBoard();
      cout << board[row][0] << " wins." << endl;
      return true;
    }
  }

  // check cols
  for (int col = 0; col < ROWS; col++)
  {
    if (board[col][0] == board[col][1] == board[col][2] && board[col][0] != ' ')
    {
      printBoard();
      cout << board[col][0] << " wins." << endl;
      return true;
    }
  }

  // check diag
  if (board[0][0] == board[1][1] == board[2][2] && board[0][0] != ' ')
  {
    printBoard();
    cout << board[0][0] << " wins." << endl;
    return true;
  }

  if (board[0][2] == board[1][1] == board[2][0] && board[2][0] != ' ')
  {
    printBoard();
    cout << board[0][2] << " wins." << endl;
    return true;
  }

  return false;
}