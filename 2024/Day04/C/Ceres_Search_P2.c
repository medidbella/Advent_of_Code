// ughhhhhhh, it took me a really loooooooooooooooong time
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Direction {
    UP = 0,
    UP_RIGHT = 1,
    RIGHT = 2,
    DOWN_RIGHT = 3,
    DOWN = 4,
    DOWN_LEFT = 5,
    LEFT = 6,
    UP_LEFT = 7,
    END = 8
};

enum DirectionType {
    TOP = 1,
    FRONT = 2,
    BOTTOM = 3,
    BACK = 4,
    END_DIR = 5
};

int isWithinBounds(int row, int col, int width, int height) {
    return row >= 0 && row < height && col >= 0 && col < width;
}

int checkForSurroundingWords(char ***array, int row, int col, int rowDir, int colDir) {
    int isValidRow = (rowDir == 1 || rowDir == -1);
    int isValidCol = (colDir == 1 || colDir == -1);
    
    if (isValidRow) {
        if (strcmp(array[row + rowDir][col + 1], "M") != 0) 
          return 0;
        if (strcmp(array[row + rowDir][col - 1], "M") != 0) 
          return 0;
        if (strcmp(array[row - rowDir][col + 1], "S") != 0)
          return 0;
        if (strcmp(array[row - rowDir][col - 1], "S") != 0)
          return 0;
    }

    if (isValidCol) {
        if (strcmp(array[row + 1][col + colDir], "M") != 0) 
          return 0;
        if (strcmp(array[row - 1][col + colDir], "M") != 0)
          return 0;
        if (strcmp(array[row + 1][col - colDir], "S") != 0)
          return 0;
        if (strcmp(array[row - 1][col - colDir], "S") != 0)
          return 0;
    }

    return 1;
}

int isValidPosition(int row, int col, int width, int height) {
    return (row - 1 >= 0 && row + 1 < height && col - 1 >= 0 && col + 1 < width);
}

int countXMASWords(char ***array, int row, int col, int height, int width) {
    int xmasWordCount = 0;
    for (int dir = TOP; dir < END_DIR; ++dir) {
        switch (dir) {
            case TOP:
                if (isValidPosition(row, col, width, height) && checkForSurroundingWords(array, row, col, 1, 0)) {
                    xmasWordCount++;
                }
                break;
            case FRONT:
                if (isValidPosition(row, col, width, height) && checkForSurroundingWords(array, row, col, 0, 1)) {
                    xmasWordCount++;
                }
                break;
            case BOTTOM:
                if (isValidPosition(row, col, width, height) && checkForSurroundingWords(array, row, col, -1, 0)) {
                    xmasWordCount++;
                }
                break;
            case BACK:
                if (isValidPosition(row, col, width, height) && checkForSurroundingWords(array, row, col, 0, -1)) {
                    xmasWordCount++;
                }
                break;
        }
    }
    return xmasWordCount;
}

int iterateThroughLetters(char ***array, int height, int width) {
    int totalXmasWords = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (strcmp(array[row][col], "A") == 0)
                totalXmasWords += countXMASWords(array, row, col, height, width);
        }
    }
    return totalXmasWords;
}

void readDataFromFile(const char *filename, char ****array, int *height, int *width) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    *height = 0;
    *width = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        (*height)++;
        *width = strlen(line);

        *array = realloc(*array, *height * sizeof(char **));
        (*array)[*height - 1] = malloc(*width * sizeof(char *));
        for (int i = 0; i < *width; i++) {
            (*array)[*height - 1][i] = malloc(2 * sizeof(char));
            (*array)[*height - 1][i][0] = line[i];
            (*array)[*height - 1][i][1] = '\0';
        }
    }

    fclose(file);
}

int main() {
    char ***array = NULL;
    int height = 0, width = 0;

    readDataFromFile("input.txt", &array, &height, &width);

    printf("Total occurrences of 'XMAS': %d\n", iterateThroughLetters(array, height, width));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);

    return 0;
}
