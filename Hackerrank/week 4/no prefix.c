#define MAX_CHAR 26


typedef struct TrieNode {
    int isEnd;
    struct TrieNode *children[MAX_CHAR];
} TrieNode;

TrieNode* createNode() {
    TrieNode node = (TrieNode)malloc(sizeof(TrieNode));
    node->isEnd = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        node->children[i] = NULL;
    }
    return node;
}

 
int insert(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }

        current = current->children[index];

        
        if (current->isEnd) {
            return 1;
        }
    }


    for (int i = 0; i < MAX_CHAR; i++) {
        if (current->children[i]) {
            return 1;
        }
    }

    current->isEnd = 1;
    return 0;
}#define MAX_CHAR 26


typedef struct TrieNode {
    int isEnd;
    struct TrieNode *children[MAX_CHAR];
} TrieNode;


TrieNode* createNode() {
    TrieNode node = (TrieNode)malloc(sizeof(TrieNode));
    node->isEnd = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        node->children[i] = NULL;
    }
    return node;
}


int insert(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }

        current = current->children[index];

        
        if (current->isEnd) {
            return 1;
        }
    }


    for (int i = 0; i < MAX_CHAR; i++) {
        if (current->children[i]) {
            return 1;
        }
    }

    current->isEnd = 1;
    return 0;
}

void noPrefix(int words_count, char** words) {
    TrieNode *root = createNode();

    for (int i = 0; i < words_count; i++) {
        if (insert(root, words[i])) {
            printf("BAD SET\n%s\n", words[i]);
            return;
        }
    }

    printf("GOOD SET\n");
}

