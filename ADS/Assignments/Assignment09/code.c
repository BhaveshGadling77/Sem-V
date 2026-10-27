#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 100
#define MAX_MEANING_LENGTH 500

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
    char meaning[MAX_MEANING_LENGTH];
} TrieNode;

TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));

    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    node->isEndOfWord = 0;
    node->meaning[0] = '\0';

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(TrieNode *root, const char *word, const char *meaning) {
    TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        char ch = tolower((unsigned char)word[i]);

        if (ch < 'a' || ch > 'z')
            continue;

        int index = ch - 'a';

        if (current->children[index] == NULL)
            current->children[index] = createNode();

        current = current->children[index];
    }

    current->isEndOfWord = 1;

    strcpy(current->meaning, meaning);
}

void loadDataset(TrieNode *root, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open dataset file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    char meaning[MAX_MEANING_LENGTH];

    while (fgets(word, sizeof(word), file) != NULL) {
        word[strcspn(word, "\n")] = '\0';

        char *separator = strchr(word, '|');

        if (separator == NULL)
            continue;

        *separator = '\0';

        strcpy(meaning, separator + 1);

        insert(root, word, meaning);
    }

    fclose(file);
}

void displaySuggestions(TrieNode *node, char *word, int depth) {
    if (node == NULL)
        return;

    if (node->isEndOfWord) {
        word[depth] = '\0';
        printf("%s - %s\n", word, node->meaning);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            word[depth] = 'a' + i;
            displaySuggestions(node->children[i], word, depth + 1);
        }
    }
}

void autoSuggest(TrieNode *root, const char *prefix) {
    TrieNode *current = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        char ch = tolower((unsigned char)prefix[i]);

        if (ch < 'a' || ch > 'z')
            continue;

        int index = ch - 'a';

        if (current->children[index] == NULL) {
            printf("\nNo suggestions found for \"%s\".\n", prefix);
            return;
        }

        current = current->children[index];
    }

    char word[MAX_WORD_LENGTH];

    strcpy(word, prefix);

    printf("\nSuggestions for \"%s\":\n", prefix);

    displaySuggestions(current, word, strlen(prefix));
}

void searchWord(TrieNode *root, const char *word) {
    TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        char ch = tolower((unsigned char)word[i]);

        if (ch < 'a' || ch > 'z')
            continue;

        int index = ch - 'a';

        if (current->children[index] == NULL) {
            printf("\nWord not found.\n");
            return;
        }

        current = current->children[index];
    }

    if (current->isEndOfWord) {
        printf("\nWord: %s\n", word);
        printf("Meaning: %s\n", current->meaning);
    } else {
        printf("\nWord not found.\n");
    }
}

void freeTrie(TrieNode *root) {
    if (root == NULL)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        freeTrie(root->children[i]);

    free(root);
}

int main() {
    TrieNode *root = createNode();

    loadDataset(root, "dictionary.txt");

    int choice;
    char query[MAX_WORD_LENGTH];

    while (1) {
        printf("\n");
        printf("1. Search Word\n");
        printf("2. Auto-Suggest\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter word: ");
                fgets(query, sizeof(query), stdin);
                query[strcspn(query, "\n")] = '\0';

                searchWord(root, query);
                break;

            case 2:
                printf("Enter prefix: ");
                fgets(query, sizeof(query), stdin);
                query[strcspn(query, "\n")] = '\0';

                autoSuggest(root, query);
                break;

            case 3:
                freeTrie(root);
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
