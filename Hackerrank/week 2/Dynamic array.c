int** create2DArray(int n, int* sizes) {
    int** arr = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(0);  
        sizes[i] = 0;
    } 
    return arr;
}


int* dynamicArray(int n, int queries_rows, int queries_columns,
 int** queries, int* result_count) {
    int lastAnswer = 0;
    int* sizes = calloc(n, sizeof(int));
    int** arr = create2DArray(n, sizes);

    int* results = malloc(queries_rows * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            sizes[idx]++;
            arr[idx] = realloc(arr[idx], sizes[idx] * sizeof(int));
            arr[idx][sizes[idx] - 1] = y;
        } else if (type == 2) {
            int value = arr[idx][y % sizes[idx]];
            lastAnswer = value;
            results[*result_count] = lastAnswer;
            (*result_count)++;
        }
    }

    // Free memory for arr and sizes if needed
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(sizes);

    return results;
}