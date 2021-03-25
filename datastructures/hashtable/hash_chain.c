/*
 In this method of hash implementation, the hashtable is
 implemented as a singly linked list to address the issue
 of collissions. If the hash function returns the same
 hash index, the key/entry is appeneded at the end of the
 list starting at the hash index
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SLOTS 32	// will have 32 singly linked lists
					  	// however, each list can have infinite
						// number of entries only limited by the
						// amount of memory

struct entry {
	struct entry *next;
	int key;			// hash key
	int value;			// value that is being stored
};

struct hashtable {
	struct entry *head;	// head of the list
	struct entry *tail; // tail of the list
};

struct hashtable[MAX_SLOTS];

// APIs
int hash(int key) {
	return (key % MAX_SLOTS);
}

int find(struct entry *list, int key) {
	// using the key, generate the hash index
	// search the val in the list
	// if found, return the entry else return -1
	int idx = 0;
	while (list != NULL) {
		if (list->key == key) {
			return idx;
		}
		idx++;
		list = list->next;
	}
	return -1;
}

void hash_insert(int key, int val) {
	// get the slot using key
	// get the head of that index and start
	// pushing the elements
	int hash_idx = hash(key);
	struct entry *entry = malloc(sizeof(*entry));
	if (!entry)
		return;

	struct entry *list_head = hashtable[hash_idx].head;

	entry->key = key;
	entry->val = val;
	entry->next = NULL;

	if (list_head == NULL) {
		list_head = entry;
		return;
	}

	// the list is not empty, let us check if the key exists
	// if exists, update the key, else add to the end of the list
	int idx = find(list, key);
	if (idx >= 0) {
		// entry exists
		struct entry *node = get_entry(list, idx);
		if (node) {
			node->key = key;
			node->val = val;
			return;
		} else {
			// this condition should not occur!!
		}
	}

	// entry does not exist
	// traverse the list and append
	while (list->next != NULL)
		list = list->next;

	list->next = entry;
}

void hash_remove(int key) {
	// remove an element from the hash table
	// matching the key
}

void hash_print(void) {
	// prints all elements at all indices in
	// in the hash table
}

void hash_free_table(void) {
	// free up the complete hash table
}

void init_table(void) {
	// initialize the hash table
}

void main(void) {
	
}
