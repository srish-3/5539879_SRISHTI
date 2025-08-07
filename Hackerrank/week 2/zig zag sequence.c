int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int t, n, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int a[n];
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        
        qsort(a, n, sizeof(int), compare);

        
        int mid = (n - 1) / 2;
        int temp = a[mid];
        a[mid] = a[n - 1];
        a[n - 1] = temp;

        
        int start = mid + 1;
        int end = n - 2;
        while (start <= end) {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }

        
        for (i = 0; i < n; i++) {
            printf("%d", a[i]);
            if (i != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
