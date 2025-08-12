char* isValid(char* s) {
    int freq[26] = {0};
    int len = strlen(s);

    
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }


    int freqCount[101] = {0}; 
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freqCount[freq[i]]++;
        }
    }

    int uniqueFreqs = 0;
    int f1 = 0, f2 = 0, c1 = 0, c2 = 0;

    for (int i = 1; i <= 100; i++) {
        if (freqCount[i] > 0) {
            uniqueFreqs++;
            if (uniqueFreqs == 1) {
                f1 = i;
                c1 = freqCount[i];
            } else if (uniqueFreqs == 2) {
                f2 = i;
                c2 = freqCount[i];
            } else {
                return "NO";
            }
        }
    }

    if (uniqueFreqs == 1) {
        return "YES";
    }

    
    if ((c1 == 1 && (f1 - 1 == f2 || f1 == 1)) ||
        (c2 == 1 && (f2 - 1 == f1 || f2 == 1))) {
        return "YES";
    }

    return "NO";
}


