/*
 * used to declare fn/class prototypes and include statements
 */

#pragma once

// #ifndef TICTACTOE_H
// #define TICTACTOE_H

#include <cassert>
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

const int ROWS = 3;
const int COLS = 3;
const char PLAYER_1 = 'x';
const char PLAYER_2 = 'o';
const int NUM_OF_PRE_MOVES = 5;

char toAlpha(int);
int toInt(char);
void printBoard();
void setBoard(char);
bool setPosition(int, int, char);
char findOpponent(char);
void calculateMove(int &, int &, char, int);
void playerMove(char);
bool isPlayerValid(char);
bool isMoveValid(int, int);
bool hasWon();
void computerMove(char);
bool isFull();

// #endif