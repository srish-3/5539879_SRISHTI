int superDigit(char* n, int k) {
    if (num < 10) return num;

    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return recursiveSuperDigit(sum);
}


int superDigit(char* n, int k) {
    long long initial_sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        initial_sum += n[i] - '0';
    }

    initial_sum *= k;
    return recursiveSuperDigit(initial_sum);
}



