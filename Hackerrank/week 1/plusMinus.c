 void plusMinus(int arr_count, int* arr) {
    int positive = 0, negative = 0, zero = 0;

    for (int i = 0; i < arr_count; i++) {
        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
        else
            zero++;
    }

    printf("%.6f\n", (float)positive / arr_count);
    printf("%.6f\n", (float)negative / arr_count);
    printf("%.6f\n", (float)zero / arr_count);