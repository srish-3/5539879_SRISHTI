char* caesarCipher(char* s, int k) {
    int len = strlen(s);
    char* result = malloc(len + 1); 

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c >= 'a' && c <= 'z') {
            result[i] = ((c - 'a' + k) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            result[i] = ((c - 'A' + k) % 26) + 'A';
        } else {
            result[i] = c; 
        }
    }

    result[len] = '\0'; 
    return result;
}

