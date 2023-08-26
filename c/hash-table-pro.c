#include <stdio.h>
#include <string.h>

typedef struct item {
    char *key;
    int   value;
} item;

item *linear_search(item *items, size_t size, const char *key) {
    for (size_t i = 0; i < size; i++) {
        if (strcmp(items[i].key, key) == 0) {
            return (&items[i]);
        }
    }

    return (NULL);
}

int main() {
    item items[] = {
        {"foo", 10},
        {"bar", 20},
        {"hello", 30},
        {"x", 40}};

    size_t total_items = sizeof(items) / sizeof(items);

    item *found = linear_search(items, total_items, "foo");

    if (found == NULL) {
        printf("linear search: value of 'foo' has no key\n");
        return (1);
    }

    printf("linear search: value of 'foo' is: %d", found->value);
    return (0);
}