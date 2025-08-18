int compareAsc(const void* a, const void* b) {
    return ((int)a - (int)b);
}
int compareDesc(const void* a, const void* b) {
    return ((int)b - (int)a);
}

int countSwaps(int* original, int* target, int n) {
    int* visited = (int*)calloc(n, sizeof(int));
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || original[i] == target[i])
            continue;

        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;

            
            int k = 0;
            while (original[k] != target[j]) k++;

            j = k;
            cycle_size++;
        }

        if (cycle_size > 0)
            swaps += (cycle_size - 1);
    }

    free(visited);
    return swaps;
}

int lilysHomework(int arr_count, int* arr) {
    int* asc = (int*)malloc(arr_count * sizeof(int));
    int* desc = (int*)malloc(arr_count * sizeof(int));
    memcpy(asc, arr, arr_count * sizeof(int));
    memcpy(desc, arr, arr_count * sizeof(int));

    qsort(asc, arr_count, sizeof(int), compareAsc);
    qsort(desc, arr_count, sizeof(int), compareDesc);

    int ascSwaps = countSwaps(arr, asc, arr_count);
    int descSwaps = countSwaps(arr, desc, arr_count);

    free(asc);
    free(desc);

    return ascSwaps < descSwaps ? ascSwaps : descSwaps;
}
