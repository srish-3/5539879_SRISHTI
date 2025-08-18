int* maxSubarray(int arr_count, int* arr, int* result_count) {
    int* maxSubarray(int arr_count, int* arr, int* result_count) {
    *result_count = 2;
    int* result = malloc(2 * sizeof(int));

    int max_subarray = arr[0];
    int current_sum = arr[0];
    int max_subsequence = arr[0] > 0 ? arr[0] : 0;
    int has_positive = arr[0] > 0;

    for (int i = 1; i < arr_count; i++) {
        
        if (current_sum < 0)
            current_sum = arr[i];
        else
            current_sum += arr[i];

        if (current_sum > max_subarray)
            max_subarray = current_sum;

        
        if (arr[i] > 0) {
            max_subsequence += arr[i];
            has_positive = 1;
        }
    }

    
    if (!has_positive) {
        max_subsequence = arr[0];
        for (int i = 1; i < arr_count; i++) {
            if (arr[i] > max_subsequence)
                max_subsequence = arr[i];
        }
    }

    result[0] = max_subarray;
    result[1] = max_subsequence;
    return result;
}
