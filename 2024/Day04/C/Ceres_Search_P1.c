#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD "XMAS"
#define WORD_LEN 4

int directions[8][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {1, 1},
    {-1, -1},
    {1, -1},
    {-1, 1}
};

int match_word(char **grid, int rows, int cols, int row, int col, int dir[2]) {
    for (int i = 0; i < WORD_LEN; i++) {
        int new_row = row + i * dir[0];
        int new_col = col + i * dir[1];
        if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols || grid[new_row][new_col] != WORD[i])
            return 0;
    }
    return 1;
}

int count_word(char **grid, int rows, int cols) {
    int count = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            for (int d = 0; d < 8; d++) {
                if (match_word(grid, rows, cols, row, col, directions[d]))
                    count++;
            }
        }
    }

    return count;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char **grid = NULL;
    int rows = 0, cols = 0;
    size_t len = 0;
    char *line = NULL;

    while (getline(&line, &len, file) != -1) {
        line[strcspn(line, "\n")] = '\0';

        grid = realloc(grid, (rows + 1) * sizeof(char *));
        grid[rows] = malloc(strlen(line) + 1);
        strcpy(grid[rows], line);

        if (rows == 0) 
            cols = strlen(line);
        rows++;
    }

    fclose(file);
    free(line); 

    int total_occurrences = count_word(grid, rows, cols);

    printf("Total occurrences of '%s': %d\n", WORD, total_occurrences);

    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}
