int birthday(int s_count, int* s, int d, int m) {
    int count = 0;
    for (int i = 0; i <= s_count - m; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += s[i + j];
        }
        if (sum == d) {
            count++;
        }
    }
    return count;
}