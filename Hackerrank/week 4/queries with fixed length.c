int* solve(int arr_count, int* arr, int queries_count, int* queries, int* result_count) {
    *result_count = queries_count;
    int* results = malloc(sizeof(int) * queries_count);

    for (int q = 0; q < queries_count; q++) {
        int d = queries[q];
        int* deque = malloc(sizeof(int) * arr_count);
        int front = 0, back = -1;
        int min_of_max = _INT_MAX_;

        for (int i = 0; i < arr_count; i++) {
            
            if (front <= back && deque[front] <= i - d)
                front++;

            
            while (front <= back && arr[deque[back]] <= arr[i])
                back--;


            deque[++back] = i;

            
            if (i >= d - 1) {
                int window_max = arr[deque[front]];
                if (window_max < min_of_max)
                    min_of_max = window_max;
            }
        }

        results[q] = min_of_max;
        free(deque);
    }

    return results;
}


