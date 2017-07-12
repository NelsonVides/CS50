/**
 * Linked lists datatypes and functions
 */

#include <stdlib.h>
#include <stdbool.h>

// node *first = NULL;

// Defining the nodes
typedef struct sllnode {
    char val;
    struct sllnode *next;
} sllnode;


/**
 * Create a new list altogether
 * sllnode *new = create (value)
 */
sllnode *create(char val) {
    sllnode *newptr = malloc(sizeof(sllnode));
        if (newptr == NULL) {return NULL;}
    newptr->val = val;
    newptr->next = NULL;
    return newptr;
}

/**
 * give in the value to insert, and the list's head
 * head = insert(val,&head)
 */
sllnode *insert(int val, sllnode *head) {
    sllnode *newptr = malloc(sizeof(sllnode));
        if (newptr == NULL) {return NULL;}
    newptr->val = val;
    newptr->next = head;
    head = newptr;
    return newptr;
}

/**
 * give in the value to look for, and the list's head
 */
bool search(int val, sllnode *head) {
    sllnode *ptr = head;
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
void destroy(sllnode *head) {
    sllnode *ptr = head;
    while (head != NULL) {
        head = ptr->next;
        free(ptr);
    }
    return;
}



int main(void) {return 0;}
