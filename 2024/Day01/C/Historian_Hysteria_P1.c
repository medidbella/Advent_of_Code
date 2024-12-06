#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }

    int left_list[1000], right_list[1000];
    int left_count = 0, right_count = 0;

    while (fscanf(file, "%d %d", &left_list[left_count], &right_list[right_count]) == 2) {
        left_count++;
        right_count++;
    }

    fclose(file);

    if (left_count != right_count) {
        fprintf("Error: Mismatched list sizes.\n");
        exit(1);
    }

    qsort(left_list, left_count, sizeof(int), compare);
    qsort(right_list, right_count, sizeof(int), compare);

    int total_distance = 0;
    for (int i = 0; i < left_count; i++) {
        total_distance += abs(left_list[i] - right_list[i]);
    }

    printf("Total distance: %d\n", total_distance);

    return 0;
}

