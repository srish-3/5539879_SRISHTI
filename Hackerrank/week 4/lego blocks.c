#define MOD 1000000007


int power(int base, int exp) {
    long long result = 1;
    long long b = base;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * b) % MOD;
        b = (b * b) % MOD;
        exp /= 2;
    }
    return (int)result;
}

int legoBlocks(int n, int m) {
    int ways[m + 1];
    ways[0] = 1;


    for (int i = 1; i <= m; i++) {
        ways[i] = 0;
        for (int j = 1; j <= 4 && j <= i; j++) {
            ways[i] = (ways[i] + ways[i - j]) % MOD;
        }
    }

    
    int total[m + 1];
    for (int i = 1; i <= m; i++) {
        total[i] = power(ways[i], n);
    }

    
    int stable[m + 1];
    stable[0] = 0;
    for (int i = 1; i <= m; i++) {
        stable[i] = total[i];
        for (int j = 1; j < i; j++) {
            stable[i] = (stable[i] - ((long long)stable[j] * total[i - j]) % MOD + MOD) % MOD;
        }
    }

    return stable[m];
}

