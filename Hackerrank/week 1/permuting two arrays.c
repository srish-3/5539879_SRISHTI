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
 
 
int cmp_asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int cmp_desc(const void* a, const void* b){
    return (*(int*)b- *(int*)a);
}

char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    static char result[4];  

    qsort(A, A_count, sizeof(int), cmp_asc);   
    qsort(B, B_count, sizeof(int), cmp_desc);  

    for (int i = 0; i < A_count; i++) {
        if (A[i] + B[i] < k) {
            sprintf(result, "NO");
            return result;
        }
    }

    sprintf(result, "YES");
    return result;

}
