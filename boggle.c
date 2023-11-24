#include "boggle.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

static bool isValid(int x, int y, int size, bool visited[MAX_SIZE][MAX_SIZE]);
static bool search(int x, int y, char *word, char grid[MAX_SIZE][MAX_SIZE], int size, bool visited[MAX_SIZE][MAX_SIZE]);

static bool isValid(int x, int y, int size, bool visited[MAX_SIZE][MAX_SIZE]) {
    return x >= 0 && x < size && y >= 0 && y < size && !visited[x][y];
}

static bool search(int x, int y, char *word, char grid[MAX_SIZE][MAX_SIZE], int size, bool visited[MAX_SIZE][MAX_SIZE]) {
    if (*word == '\0') {
        return true;
    }

    if (!isValid(x, y, size, visited) || grid[x][y] != *word) {
        return false;
    }

    visited[x][y] = true;

    // Directions: right, down, left, up, diagonals
    int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
    int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};

    for (int dir = 0; dir < 8; dir++) {
        if (search(x + dx[dir], y + dy[dir], word + 1, grid, size, visited)) {
            return true;
        }
    }

    visited[x][y] = false;
    return false;
}

void printGrid(char grid[MAX_SIZE][MAX_SIZE], int size, bool visited[MAX_SIZE][MAX_SIZE]) {
    printf("+++++++++++\n");
    for (int i = 0; i < size; i++) {
        printf("| ");
        for (int j = 0; j < size; j++) {
            if (visited[i][j]) {
                printf("%c ", toupper(grid[i][j]));
            } else {
                printf("%c ", grid[i][j]);
            }
            
        }
        printf("|\n");
    }
    printf("+++++++++++\n");
}

// Main function to solve the Boggle puzzle
bool boggleSolver(int size, char grid[MAX_SIZE][MAX_SIZE], bool visited[MAX_SIZE][MAX_SIZE], char *word) {
    // Search for the word in the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (search(i, j, word, grid, size, visited)) {
                printGrid(grid, size, visited);
                return true;
            }
        }
    }

    printf("The word \"%s\" is not in the grid.\n", word);
    return false;
}
