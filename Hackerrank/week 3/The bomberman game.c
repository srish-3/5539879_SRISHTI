#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

char** copyGrid(char** grid, int rows, int cols) {
    char** newGrid = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        newGrid[i] = malloc((cols + 1) * sizeof(char));
        strcpy(newGrid[i], grid[i]);
    }
    return newGrid;
}

char** detonate(char** grid, int rows, int cols) {
    char** result = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        result[i] = malloc((cols + 1) * sizeof(char));
        for (int j = 0; j < cols; j++) {
            result[i][j] = 'O';
        }
        result[i][cols] = '\0';
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'O') {
                result[i][j] = '.';
                if (i > 0) result[i - 1][j] = '.';
                if (i < rows - 1) result[i + 1][j] = '.';
                if (j > 0) result[i][j - 1] = '.';
                if (j < cols - 1) result[i][j + 1] = '.';
            }
        }
    }

    return result;
} char** copyGrid(char** grid, int rows, int cols) {
    char** newGrid = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        newGrid[i] = malloc((cols + 1) * sizeof(char));
        strcpy(newGrid[i], grid[i]);
    }
    return newGrid;
}

char** detonate(char** grid, int rows, int cols) {
    char** result = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        result[i] = malloc((cols + 1) * sizeof(char));
        for (int j = 0; j < cols; j++) {
            result[i][j] = 'O';
        }
        result[i][cols] = '\0';
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'O') {
                result[i][j] = '.';
                if (i > 0) result[i - 1][j] = '.';
                if (i < rows - 1) result[i + 1][j] = '.';
                if (j > 0) result[i][j - 1] = '.';
                if (j < cols - 1) result[i][j + 1] = '.';
            }
        }
    }

    return result;
}
char** bomberMan(int n, int r, int c, char** grid, int grid_rows, int grid_columns) {
    if (n == 1) return copyGrid(grid, r, c);

    if (n % 2 == 0) {
        char** fullGrid = malloc(r * sizeof(char*));
        for (int i = 0; i < r; i++) {
            fullGrid[i] = malloc((c + 1) * sizeof(char));
            for (int j = 0; j < c; j++) {
                fullGrid[i][j] = 'O';
            }
            fullGrid[i][c] = '\0';
        }
        return fullGrid;
    }


