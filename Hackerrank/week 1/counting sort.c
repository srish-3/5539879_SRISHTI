include <assert.h>
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


int* countingSort(int arr_count, int* arr) {
    static int result[100] = {0};

    for (int i = 0; i < arr_count; i++) {
        result[arr[i]]++;
    }

    return result;
}
