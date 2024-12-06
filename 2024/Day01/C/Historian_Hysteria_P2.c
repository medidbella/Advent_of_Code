
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 100000

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }

    int left_list[1000], right_list[1000];
    int left_count = 0, right_count = 0;
    int frequency[MAX_VAL] = {0};
    long long similarity_score = 0;

    while (fscanf(file, "%d %d", &left_list[left_count], &right_list[right_count]) == 2) {
        frequency[right_list[right_count]]++;
        left_count++;
        right_count++;
    }

    fclose(file);

    for (int i = 0; i < left_count; i++) {
        int left_num = left_list[i];
        similarity_score += (long long)left_num * frequency[left_num];
    }

    printf("Similarity score: %lld\n", similarity_score);

    return 0;
}

