int* icecreamParlor(int m, int arr_count, int* arr, int* result_count) {
    *result_count = 2;

    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) return NULL;

    for (int i = 0; i < arr_count - 1; i++) {
        for (int j = i + 1; j < arr_count; j++) {
            if (arr[i] + arr[j] == m) {
                result[0] = i + 1;
                result[1] = j + 1;
                return result;
            }
        }
    }

    return NULL;
}