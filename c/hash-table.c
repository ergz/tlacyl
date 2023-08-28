#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH_TABLE_SIZE 16

typedef struct KV {
    char *key;
    char *value;
} KV;

typedef struct Node {
    KV           kv;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node *data[MAX_HASH_TABLE_SIZE];
} HashTable;

HashTable *new_hashtable() {
    HashTable *ht = malloc(sizeof(HashTable));
    for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
        ht->data[i] = NULL;
    }

    return (ht);
}

Node *new_node() {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;

    return (node);
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
        if ((h.data[i] != NULL) && (strcmp(h.data[i]->kv.key, key) == 0)) {
            return (&h.data[i]->kv);
        }
    }

    return (NULL);
}

char *get_value(HashTable ht, char *key) {
    int hash_key = hash(key);

    Node *node_at_hash = ht.data[hash_key];

    if (node_at_hash == NULL) {
        fprintf(stderr, "ERROR: key not found in hashtable");
        return;
    }

    // if next is NULL then this is the only at this hash so just return it
    if (node_at_hash->next == NULL) {
        return node_at_hash->kv.value;
    }

    return kv->value;
}

void insert_kv(HashTable *ht, char *key, char *value) {
    int hashed_key = hash(key);

    Node *current = ht->data[hashed_key];

    while (current) {
        if (strcmp(current->kv.key, key) == 0) {
            current->kv.value = value;
            return;
        }

        current = current->next;
    }

    Node *new = new_node();
    new->kv.key = key;
    new->kv.value = value;
    new->next = current;
    ht->data[hashed_key] = new;
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
    char *result = get_value(*h, "hello");
    printf("the value corresponding to the key 'hello' is: '%s'", result);

    return 0;
}
