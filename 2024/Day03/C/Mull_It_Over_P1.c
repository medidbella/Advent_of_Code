#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_valid_number(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int extract_and_multiply(const char *start) {
    int num1 = 0, num2 = 0;
    char buffer[100];

    const char *comma = strchr(start, ',');
    if (!comma || (comma - start) >= sizeof(buffer))
      return 0;
    strncpy(buffer, start, comma - start);
    buffer[comma - start] = '\0';

    if (!is_valid_number(buffer))
      return 0;
    num1 = atoi(buffer);

    const char *end = strchr(comma + 1, ')');
    if (!end || (end - (comma + 1)) >= sizeof(buffer))
      return 0;
    strncpy(buffer, comma + 1, end - (comma + 1));
    buffer[end - (comma + 1)] = '\0';

    if (!is_valid_number(buffer))
    return 0;
    num2 = atoi(buffer);

    return num1 * num2;
}


int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    fclose(file);

    int total = 0;
    const char *pos = buffer;

    while ((pos = strstr(pos, "mul(")) != NULL) {
        const char *open_brace = pos + 4;
        total += extract_and_multiply(open_brace);
        pos += 4;
    }

    printf("Total sum of valid multiplications: %d\n", total);

    free(buffer);
    return 0;
}

