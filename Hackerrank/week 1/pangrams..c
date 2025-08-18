char* pangrams(char* s) {
    int letters[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            char lower = tolower(s[i]);
            letters[lower - 'a'] = 1;
        }
    }

    
    for (int i = 0; i < 26; i++) {
        if (letters[i] == 0) {
            return "not pangram";
        }
    }
    return "pangram";
}
int main() {
    char input[1005];
    fgets(input, sizeof(input), stdin);

    printf("%s\n", pangrams(input));
    return 0;
}

