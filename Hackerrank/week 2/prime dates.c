#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isLeap(int year) {
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int getDays(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) return 29;
    return daysInMonth[month - 1];
}


int getDateValue(int d, int m, int y) {
    return d * 1000000 + m * 10000 + y;
}


int isLucky(int d, int m, int y) {
    int val = getDateValue(d, m, y);
    return (val % 4 == 0 || val % 7 == 0);
}




int main() {
    int d1, m1, y1;
    int d2, m2, y2;
    scanf("%d-%d-%d", &d1, &m1, &y1);
    scanf("%d-%d-%d", &d2, &m2, &y2);

    int result = findLuckyDates(d1, m1, y1, d2, m2, y2);
    printf("%d\n", result);

    return 0;
}

