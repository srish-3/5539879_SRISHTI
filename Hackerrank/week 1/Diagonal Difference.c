int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int primary = 0;
    int secondary = 0;

    for (int i = 0; i < arr_rows; i++) {
        primary += arr[i][i];
        secondary += arr[i][arr_columns - i - 1];
    }

    return abs(primary - secondary);
}