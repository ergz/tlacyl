#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
    char *data[16];
} HashTable;

HashTable *new_hashtable() {
    HashTable *ht = malloc(sizeof(HashTable));
    for (int i = 0; i < 16; i++) {
        ht->data[i] = NULL;
    }

    return (ht);
}

int get_index_for_letter(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return (letter - 'a') + 1;
    } else {
        return -1;
    }
}

int hash(char *word) {
    int word_len = strlen(word);
    int accum = 1;
    int index;
    for (int i = 0; i < word_len; i++) {
        index = get_index_for_letter(word[i]);
        accum *= index;
    }

    return accum % 16;
}

char *get(HashTable *h, char *key) {
    int hash_val = hash(key);
    return h->data[hash_val];
}

void insert(HashTable *h, char *key, char *value) {
    int hashed_key = hash(key);

    if (h->data[hashed_key] != NULL) {
        fprintf(stderr, "ERROR: collision!");
        exit(1);
    }

    h->data[hashed_key] = value;
}

void delete(HashTable *h, char *key) {
    int hashed_key = hash(key);
    h->data[hashed_key] = NULL;
}

int main() {
    HashTable *hash_table = new_hashtable();
    char      *key = "hello";
    insert(hash_table, key, "world");
    insert(hash_table, "hlleo", "world");
    char *res = get(hash_table, "hello");

    printf("the value at key '%s' is '%s'", key, res);

    return 0;
}
