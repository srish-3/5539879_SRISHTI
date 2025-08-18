bool isPowerOfTwo(long n) {
    return (n != 0) && ((n & (n - 1)) == 0);
}

 
long largestPowerOfTwoLessThan(long n) {
    long power = 1;
    while (power << 1 < n) {
        power <<= 1;
    }
    return power;
}

char* counterGame(long n) {
    int turn = 0; // 0 for Louise, 1 for Richard

    while (n != 1) {
        if (isPowerOfTwo(n)) {
            n /= 2;
        } else {
            n -= largestPowerOfTwoLessThan(n);
        }
        turn = 1 - turn;
    }

    return turn == 1 ? "Louise" : "Richard";
} 
