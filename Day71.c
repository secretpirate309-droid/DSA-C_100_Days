#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Implement a hash table using quadratic probing with formula:



#define SIZE 10
#define EMPTY -1

typedef struct {
    int key;
    int value;
    bool is_occupied;
} Entry;

typedef struct {
    Entry* table;
    int capacity;
    int size;
} HashTable;

HashTable* create_table(int capacity) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->capacity = capacity;
    ht->size = 0;
    ht->table = (Entry*)malloc(sizeof(Entry) * capacity);
    for (int i = 0; i < capacity; i++) {
        ht->table[i].key = EMPTY;
        ht->table[i].is_occupied = false;
    }
    return ht;
}

int hash_function(int key, int capacity) {
    return key % capacity;
}

void insert(HashTable* ht, int key, int value) {
    if (ht->size == ht->capacity) return;

    int h = hash_function(key, ht->capacity);
    for (int i = 0; i < ht->capacity; i++) {
        int index = (h + i * i) % ht->capacity;
        if (!ht->table[index].is_occupied) {
            ht->table[index].key = key;
            ht->table[index].value = value;
            ht->table[index].is_occupied = true;
            ht->size++;
            return;
        }
    }
}

int search(HashTable* ht, int key) {
    int h = hash_function(key, ht->capacity);
    for (int i = 0; i < ht->capacity; i++) {
        int index = (h + i * i) % ht->capacity;
        if (!ht->table[index].is_occupied) return -1;
        if (ht->table[index].key == key) return ht->table[index].value;
    }
    return -1;
}

void display(HashTable* ht) {
    for (int i = 0; i < ht->capacity; i++) {
        if (ht->table[i].is_occupied)
            printf("[%d]: %d -> %d\n", i, ht->table[i].key, ht->table[i].value);
        else
            printf("[%d]: EMPTY\n", i);
    }
}

int main() {
    HashTable* ht = create_table(SIZE);

    insert(ht, 1, 10);
    insert(ht, 11, 20);
    insert(ht, 21, 30);
    insert(ht, 7, 70);

    display(ht);

    int val = search(ht, 21);
    if (val != -1) printf("\nFound: %d\n", val);

    return 0;
}