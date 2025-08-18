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


int findLuckyDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    int count = 0;

    while (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 <= d2)) {
        if (isLucky(d1, m1, y1)) count++;

        d1++;
        if (d1 > getDays(m1, y1)) {
            d1 = 1;
            m1++;
            if (m1 > 12) {
                m1 = 1;
                y1++;
            }
        }
    }

    return count;
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

