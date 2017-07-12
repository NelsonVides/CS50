/**
 * Linked lists datatypes and functions
 */

#include <stdlib.h>
#include <stdbool.h>

// node *first = NULL;

// Defining the nodes
typedef struct dllnode {
    char val;
    struct dllnode *prev;
    struct dllnode *next;
} dllnode;


/**
 * Create a new list altogether
 * dllnode *new = create (value)
 */
dllnode *create(char val) {
    dllnode *newptr = malloc(sizeof(dllnode));
        if (newptr == NULL) {return NULL;}
    newptr->val = val;
    newptr->prev = NULL;
    newptr->next = NULL;
    return newptr;
}

/**
 * give in the value to insert, and the list's head
 * head = insert(val,&head)
 */
dllnode *insert(int val, dllnode *head) {
    dllnode *newptr = malloc(sizeof(dllnode));
        if (newptr == NULL) {return NULL;}
    newptr->val = val;
    newptr->prev = NULL;
    newptr->next = head;
    head->prev = newptr;
    head = newptr;
    return newptr;
}

/**
 * give in the value to look for, and the list's head
 */
bool search(int val, dllnode *head) {
    dllnode *ptr = head;
    while (ptr != NULL) {
        if (ptr->val == val) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

/**
 * destroy that shit!
 */
void destroy(dllnode *head) {
    dllnode *ptr = head;
    while (head != NULL) {
        head = ptr->next;
        free(ptr);
    }
    return;
}



int main(void) {return 0;}
