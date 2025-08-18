qsort(arr, arr_count, sizeof(int), compare); // Sort array

    int min_unfairness = INT_MAX;

    for (int i = 0; i <= arr_count - k; i++) {
        int unfairness = arr[i + k - 1] - arr[i];
        if (unfairness < min_unfairness) {
            min_unfairness = unfairness;
        }
    }

    return m
}