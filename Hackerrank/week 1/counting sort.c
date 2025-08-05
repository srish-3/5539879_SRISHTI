int* countingSort(int arr_count, int* arr) {
    static int result[100] = {0};

    for (int i = 0; i < arr_count; i++) {
        result[arr[i]]++;
    }

    return result;
}
