import string

alphabet = [i for i in string.ascii_lowercase]

alphabet.split()


def linear_search(val, arr):
    for i, letter in enumerate(arr):
        if val == letter:
            return i + 1

    return None


def hash(word):
    split_word = [i for i in word]
    split_prods = [linear_search(i, alphabet) for i in split_word]
    hash_key = 1
    for i in split_prods:
        hash_key *= i

    return hash_key % 16


def insert_at_hash(key, value, container):
    key_hash = hash(key)

    if container[key_hash] is None:
        # no collision just insert and return
        container[key_hash] = value
        return container
    else:
        # resolve collision
        existing_value = container[key_hash]


container = [None for i in range(15)]

insert_at_hash("bad", "evil", container)


container[hash("bad")] = "evil"


d = {"bad": "evil"}
d["bad"]
