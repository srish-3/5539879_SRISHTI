void minimumBribes(int q_count, int* q) {
    int bribes = 0;
    for (int i = 0; i < q_count; i++) {

        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }


        for (int j = fmax(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }

    printf("%d\n", bribes);
}


