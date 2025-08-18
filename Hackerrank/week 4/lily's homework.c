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

int compareAsc(const void* a, const void* b) {
    return ((int)a - (int)b);
}
int compareDesc(const void* a, const void* b) {
    return ((int)b - (int)a);
}

int countSwaps(int* original, int* target, int n) {
    int* visited = (int*)calloc(n, sizeof(int));
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || original[i] == target[i])
            continue;

        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;

            
            int k = 0;
            while (original[k] != target[j]) k++;

            j = k;
            cycle_size++;
        }

        if (cycle_size > 0)
            swaps += (cycle_size - 1);
    }

    free(visited);
    return swaps;
}

int lilysHomework(int arr_count, int* arr) {
    int* asc = (int*)malloc(arr_count * sizeof(int));
    int* desc = (int*)malloc(arr_count * sizeof(int));
    memcpy(asc, arr, arr_count * sizeof(int));
    memcpy(desc, arr, arr_count * sizeof(int));

    qsort(asc, arr_count, sizeof(int), compareAsc);
    qsort(desc, arr_count, sizeof(int), compareDesc);

    int ascSwaps = countSwaps(arr, asc, arr_count);
    int descSwaps = countSwaps(arr, desc, arr_count);

    free(asc);
    free(desc);

    return ascSwaps < descSwaps ? ascSwaps : descSwaps;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    int result = lilysHomework(n, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
