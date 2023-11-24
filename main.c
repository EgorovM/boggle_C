#include "boggle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


extern char *gameGrid;  // Reference the global gameGrid from boggle.c

char *trimGrid(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str) || *str == '"') str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && (isspace((unsigned char)*end) || *end == '"')) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

int main(int argc, char **argv) {
    char *grid = NULL;
    char *word = NULL;
    int size = 4;

    char gameGrid[MAX_SIZE][MAX_SIZE];
    bool visited[MAX_SIZE][MAX_SIZE];
    memset(visited, false, sizeof(visited));

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-g") == 0 && i + 1 < argc) {
            grid = trimGrid(argv[++i]);
        } else if (strcmp(argv[i], "-w") == 0 && i + 1 < argc) {
            word = argv[++i];
        } else if (strcmp(argv[i], "-s") == 0 && i + 1 < argc) {
            size = atoi(argv[++i]);
        }
    }
    // // Check if grid is provided
    if (!grid) {
        fprintf(stderr, "Grid not provided\n");
        return 84;
    }

    if ((int)strlen(grid) != size * size) {
        fprintf(stderr, "Grid has incorrect length\n");
        return 84;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            gameGrid[i][j] = grid[i * size + j];
        }
    }

    if (word) {
        // Search for the word
        boggleSolver(size, gameGrid, visited, word);
    } else {
        printGrid(gameGrid, size, visited);
        char inputWord[1000000]; // Assuming max word length
        printf("> ");
        while (scanf("%s", inputWord) == 1) {
            if(boggleSolver(size, gameGrid, visited, inputWord)) {
                break;
            }
            printf("> ");
        }
    }
    return 0;
}