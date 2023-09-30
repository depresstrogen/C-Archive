#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    struct Node* next;
    struct Node* prev;
    int value;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int size;
};

/*
    Prints all values in list
*/
char printAll(struct LinkedList *list) {
    // Start at head
    struct Node* nodeptr = list -> head;
    printf("[");
    // Loop through each node
    for(int i = 0; i < list -> size; i++) {
        printf("%d", nodeptr -> value);
        // Print comma for all except last
        if(i != list -> size - 1) {
            printf(", ");
        }
        nodeptr = nodeptr -> next;
    }
    printf("]\n");
}//printAll

/*
    Adds node at end of list
*/
void add(struct LinkedList *list, int val) {
    // Make a new node pointer with new memory allocated to it
    struct Node *node = malloc(sizeof(struct Node));
    // Add value
    node -> value = val;

    if (list -> size == 0) {
        //Make everything that node
        list -> head = node;
        list -> tail = node;
        node -> next = node;
        node -> prev = node;
    } else {
        // tail.next = node
        list -> tail -> next = node;
        // node.next = tail
        node -> prev = list -> tail;
        // node.next = head
        node -> next = list -> head;
        // head.prev = node;
        list -> head -> prev = node;
        // tail = node
        list -> tail = node;
    }

    list -> size ++;
}//add

void insert(struct LinkedList *list, int val, int index) {
    // OOB conditions
    if (index < 0 || index > list -> size) {
        exit(EXIT_FAILURE);
    }

    // New node for value
    struct Node* node = malloc(sizeof(struct Node));
    node -> value = val;

    // Start count at head
    struct Node* nodeptr = list -> head;

    // Skip to index
    for(int i = 0; i < index; i++) {
        nodeptr = nodeptr -> next;
    }

    // Link them
    node -> next = nodeptr;
    node -> prev = nodeptr -> prev;
    node -> prev -> next = node;
    node -> next -> prev = node;
    
    list -> size ++;
}//insert

/*
    Deletes node at the end of list
*/
void deleteLast(struct LinkedList *list) {
    if (list -> size == 0) {
        // Do nothing
    } else {
        // Last node = tail to save pointer
        struct Node *last = list -> tail;

        // Move tail one node back
        list -> tail = list ->  tail -> prev;

        // Link new tail with head
        list -> tail -> next = list -> head;
        list -> head -> prev = list -> tail;

        list -> size --;

        // Free memory of last
        free(last);
    }

}//deleteLast

void delete(struct LinkedList *list, int index) {
    // OOB conditions
    if (index < 0 || index > list -> size || list -> size == 0) {
        return;
    }

    //Start count at head
    struct Node* nodeptr = list -> head;

    // Skip to index
    for(int i = 0; i < index; i++) {
        nodeptr = nodeptr -> next;
    }

    if (index == 0) {
        // Set head to replace if first
        list -> head = nodeptr -> next;
    }

    if (index == (list -> size) - 1) {
        // Set tail to replace if last
        list -> tail = nodeptr -> prev;
    }

    // Link the gap
    nodeptr -> prev -> next = nodeptr -> next;
    nodeptr -> next -> prev = nodeptr -> prev;

    // Free pointer
    free(nodeptr);

    list -> size --;
}

int get(struct LinkedList* list, int index) {
    // OOB conditions
    if (index < 0 || index >= list -> size || list -> size == 0) {
        return -1;
    }

    //Start count at head
    struct Node* nodeptr = list -> head;

    // Skip to index
    for(int i = 0; i < index; i++) {
        nodeptr = nodeptr -> next;
    }

    return nodeptr -> value;
}
/*
    Doubly Linked List implementation in C
*/
int main() {
    // Allocate space for linked list
    struct LinkedList *myList = malloc(sizeof(struct LinkedList));
    myList -> size = 0;

    add(myList, 2);
    printAll(myList);

    add(myList, 4);
    printAll(myList);

    add(myList, 6);
    printAll(myList);

    add(myList, 8);
    printAll(myList);

    deleteLast(myList);
    printAll(myList);

    deleteLast(myList);
    printAll(myList);

    add(myList, 1);
    add(myList, 3);
    add(myList, 5);
    add(myList, 7);
    printAll(myList);

    deleteLast(myList);
    printAll(myList);

    deleteLast(myList);
    printAll(myList);

    insert(myList, 9, 2);
    printAll(myList);

    insert(myList, 0, 5);
    printAll(myList);

    delete(myList, 1);

    printf("Gets (%d, ", get(myList, 0));
    printf("%d, ", get(myList, 1));
    printf("%d, ", get(myList, 2));
    printf("%d, ", get(myList, 3));
    printf("%d, ", get(myList, 4));
    printf("%d)\n", get(myList, 5));

    printAll(myList);

    delete(myList, 4);
    printAll(myList);

    delete(myList, 0);
    printAll(myList);

    delete(myList, 1);
    printAll(myList);

    delete(myList, 1);
    printAll(myList);

    delete(myList, 0);
    printAll(myList);


    delete(myList, 500);
    printAll(myList);

    delete(myList, 0);
    printAll(myList);
    
    return 0;
}//main