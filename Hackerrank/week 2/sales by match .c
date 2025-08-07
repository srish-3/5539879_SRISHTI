int sockMerchant(int n, int ar_count, int* ar) {
    int colorCount[101] = {0}; 
    int pairs = 0;

    
    for (int i = 0; i < n; i++) {
        colorCount[ar[i]]++;
    }

    
    for (int i = 1; i <= 100; i++) {
        pairs += colorCount[i] / 2;
    }

    return pairs;
}
