// boggle.h
#ifndef BOGGLE_H
#define BOGGLE_H

#include <stdbool.h>

#define MAX_SIZE 1000  // Assuming the maximum size of the grid

bool boggleSolver(int size, char grid[MAX_SIZE][MAX_SIZE], bool visited[MAX_SIZE][MAX_SIZE], char *word);
void printGrid(char grid[MAX_SIZE][MAX_SIZE], int size, bool visited[MAX_SIZE][MAX_SIZE]);

#endif