#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define HASH_TABLE_SIZE 10

struct Employee {
    int key;
    // Other employee record fields can be added here
};

struct EmployeeHashTable {
    struct Employee* table[HASH_TABLE_SIZE];
    int occupied[HASH_TABLE_SIZE];
};

// Hash function
int hashFunction(int key) {
    return key % HASH_TABLE_SIZE;
}

// Insert an employee into the hash table
void insert(struct EmployeeHashTable* ht, struct Employee* emp) {
    int index = hashFunction(emp->key);
    int i = index;
    do {
        if (ht->occupied[i] == 0) {
            ht->table[i] = emp;
            ht->occupied[i] = 1;
            printf("Employee with key %d inserted at index %d\n", emp->key, i);
            return;
        }
        i = (i + 1) % HASH_TABLE_SIZE;
    } while (i != index);

    printf("Hash table is full, cannot insert employee with key %d\n", emp->key);
}

// Search for an employee in the hash table
struct Employee* search(struct EmployeeHashTable* ht, int key) {
    int index = hashFunction(key);
    int i = index;
    do {
        if (ht->occupied[i] == 1 && ht->table[i]->key == key) {
            return ht->table[i];
        }
        i = (i + 1) % HASH_TABLE_SIZE;
    } while (i != index);

    return NULL; // Employee not found
}

int main() {
    struct EmployeeHashTable hashTable;
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        hashTable.table[i] = NULL;
        hashTable.occupied[i] = 0;
    }

    // Example: Inserting employees
    struct Employee emp1 = {1234}; // Example key
    struct Employee emp2 = {5678}; // Example key

    insert(&hashTable, &emp1);
    insert(&hashTable, &emp2);

    // Example: Searching for an employee
    int searchKey = 5678; // Example key to search
    struct Employee* foundEmp = search(&hashTable, searchKey);
    if (foundEmp != NULL) {
        printf("Employee with key %d found\n", searchKey);
    } else {
        printf("Employee with key %d not found\n", searchKey);
    }

    return 0;
}
