#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE 10000
#define MAX_LEVELS 1000

bool is_safe(int levels[], int n) {
    if (n < 2) 
      return false;
    
    bool is_increasing = levels[1] > levels[0];
    
    for (int i = 1; i < n; i++) {
        int diff = levels[i] - levels[i - 1];

        if (diff < -3 || diff > 3 || diff == 0)
            return false;
        if (is_increasing && diff < 0)
            return false;
        if (!is_increasing && diff > 0)
            return false;
    }

    return true;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_LINE];
    int safe_count = 0;

    while (fgets(line, MAX_LINE, file)) {
        int levels[MAX_LEVELS];
        int n = 0;

        char *token = strtok(line, " ");
        while (token) {
            levels[n++] = atoi(token);
            token = strtok(NULL, " ");
        }

        if (is_safe(levels, n))
            safe_count++;
    }

    fclose(file);

    printf("Number of safe reports: %d\n", safe_count);

    return 0;
}
