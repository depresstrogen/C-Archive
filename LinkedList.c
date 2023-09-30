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
    struct Node* nodeptr = list -> head;
    //printf("%d", nodeptr);
    for(int i = 0; i < list -> size; i++) {
        //printf("A");
        printf("%d", nodeptr -> value);
        nodeptr = nodeptr -> next;
    }
}

/*
    Adds node at end of list
*/
void add(struct LinkedList *list, int v) {
    struct Node *node = malloc(sizeof(struct Node));
    node->value = v;
    

    if (list -> size == 0) {
        list -> head = node;
        list -> tail = node;
        node -> next = node;
        node -> prev = node;
        
    } else {

        // list.tail.next = node
        list -> tail -> next = node;

        //
        node -> prev = list -> tail;

        // list.tail = node
        list -> tail = node;

        //node.next = list.head
        node -> next = list -> head;
        list -> head -> prev = node;
    }
    list -> size ++;
}

/*
    Deletes node at the end of list
*/
void delete(struct LinkedList *list) {
    if (list -> size == 0) {
        
    } else{
        struct Node *last = list -> tail;

        list -> tail =list ->  tail -> prev;

        list -> tail -> next = list -> head;
        list -> head -> prev = list -> tail;

        list -> size --;

        free(last);
    }
   
}

/*
    Doubly Linked List implementation in C
*/
int main() {
    struct LinkedList *myList = malloc(sizeof(struct LinkedList));
    myList -> size = 0;

    add(myList, 2);
    add(myList, 4);
    add(myList, 6);
    add(myList, 8);

    printAll(myList);
    printf("\n");

    delete(myList);
    printAll(myList);
    printf("\n");

    delete(myList);
    printAll(myList);
    printf("\n");

    add(myList, 1);
    add(myList, 3);
    add(myList, 5);
    add(myList, 7);
    printAll(myList);
    printf("\n");

    delete(myList);
    printAll(myList);
    printf("\n");

    delete(myList);
    printAll(myList);
    printf("\n");

    return 0;
}