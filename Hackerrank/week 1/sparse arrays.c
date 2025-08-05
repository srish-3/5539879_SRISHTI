#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* matchingStrings(int strings_count, char strings[][21], int queries_count, char queries[][21], int* result_count) {
    *result_count = queries_count;
    int* result = malloc(queries_count * sizeof(int));  // Corrected memory allocation

    for (int i = 0; i < queries_count; i++) {
        int count = 0;
        for (int j = 0; j < strings_count; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        result[i] = count;
    }

    return result;
}

int main() {
    int n = 5;
    char strings[5][21] = {"grape", "banana", "grape", "pineapple", "banana"};

    int q = 3;
    char queries[3][21] = {"apple", "banana", "grape"};

    int result_count;
    int* counts = matchingStrings(n, strings, q, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", counts[i]);
    }

    free(counts);  // Free dynamically allocated memory
    return 0;
}