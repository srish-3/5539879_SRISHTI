#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    char s[10001], t[10001];
    scanf("%s", s);
    scanf("%s", t);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == t[i])
            printf("0");
        else
            printf("1");
    }
    printf("\n");
    return 0;
}

