char* highestValuePalindrome(char* s, int n, int k) {
    char* result = (char*)malloc((n + 1) * sizeof(char));
    strcpy(result, s);

    int* changed = (int*)calloc(n, sizeof(int));
    int left = 0, right = n - 1;
    int minChanges = 0;

    
    while (left < right) {
        if (result[left] != result[right]) {
            char maxChar = result[left] > result[right] ? result[left] : result[right];
            result[left] = result[right] = maxChar;
            changed[left] = changed[right] = 1;
            minChanges++;
        }
        left++;
        right--;
    }

    if (minChanges > k) {
        free(result);
        free(changed);
        return "-1";
    }

        left = 0;
    right = n - 1;
    int remaining = k - minChanges;

    while (left <= right) {
        if (left == right) {
            if (remaining > 0 && result[left] != '9') {
                result[left] = '9';
            }
        } else {
            if (result[left] != '9') {
                if (changed[left] || changed[right]) {
                    if (remaining >= 1) {
                        result[left] = result[right] = '9';
                        remaining--;
                    }
                } else {
                    if (remaining >= 2) {
                        result[left] = result[right] = '9';
                        remaining -= 2;
                    }
                }
            }
        }
        left++;
        right--;
    }

    result[n] = '\0';
    free(changed);
    return result;
}

