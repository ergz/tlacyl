#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH_TABLE_SIZE 16

typedef struct KV {
    char *key;
    char *value;
    KV    data[MAX_HASH_TABLE_SIZE];
} KV;

typedef struct HashTable {
    KV data[MAX_HASH_TABLE_SIZE];
} HashTable;

HashTable *new_hashtable() {
    HashTable *ht = malloc(sizeof(HashTable));
    for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
        ht->data[i].key = NULL;
        ht->data[i].value = NULL;
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

KV *find_KV_in_ht(HashTable h, char *key) {
    for (size_t i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
        if ((h.data[i].key != NULL) && (strcmp(h.data[i].key, key) == 0)) {
            return (&h.data[i]);
        }
    }

    return (NULL);
}

char *get_value(HashTable ht, char *key) {
    KV *kv = find_KV_in_ht(ht, key);

    return kv->value;
}

void insert_kv(HashTable *ht, char *key, char *value) {
    KV *kv = find_KV_in_ht(*ht, key);

    if (kv == NULL) {
        int hash_val = hash(key);
        if (ht->data[hash_val].key != NULL) {  // value with has exists
            // come up with clever way to resolve the collision
        } else {
            ht->data[hash_val].key = key;
            ht->data[hash_val].value = value;
        }
    } else {
        printf("key already in HashTable\n");
    }
}

// char *get(HashTable *h, char *key) {
//     int hash_val = hash(key);
//     return h->data[hash_val];
// }

// void insert(HashTable *h, char *key, char *value) {
//     int hashed_key = hash(key);

//     if (h->data[hashed_key] != NULL) {
//         fprintf(stderr, "ERROR: collision!");
//         exit(1);
//     }

//     h->data[hashed_key] = value;
// }

// void delete(HashTable *h, char *key) {
//     int hashed_key = hash(key);
//     h->data[hashed_key] = NULL;
// }

int main() {
    HashTable *h = new_hashtable();

    // test
    insert_kv(h, "hello", "world");
    KV   *kv = find_KV_in_ht(*h, "hello");
    char *result = get_value(*h, "hello");
    printf("the value corresponding to the key 'hello' is: '%s'", result);

    return 0;
}
