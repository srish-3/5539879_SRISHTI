
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

        for (i = 0; i < n; i++) {
            printf("%d", a[i]);
            if (i != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
