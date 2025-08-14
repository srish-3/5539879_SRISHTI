long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
    long* diff = (long*)calloc(n + 2, sizeof(long));

    
    for (int i = 0; i < queries_rows; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        diff[a] += k;
        diff[b + 1] -= k;
    }

    
    long max = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += diff[i];
        if (current > max) {
            max = current;
        }
    }

    free(diff);  
    return max;
}
