/** TRIES, with the alphabet */

#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "tries.h"

#define LENGTH 45
#define ALPHABET 27
// node *first = NULL;

/** Defining the nodes */
typedef struct _trie {
    bool isword; 
    struct _trie *alfabeto[ALPHABET];
} trie;
trie *ROOTOFTRIE = NULL;


/** trie *root = createtrie()
 * Create a new list altogether */
trie *createtrie() {
    trie *newptr = malloc(sizeof(trie));
        if (newptr == NULL) {return NULL;}
    initnode(newptr);
    return newptr;
}



/**
 * give in the value to insert, and the list's root
 * root = insert(val,&root)
 */
int insert(char *palabra, trie *root) {
    
    // aux pointers not to lose data just in case
    char *wordptr = palabra;
    trie *nodeptr = root;
    
    // insert char by char until we reach the end of the word
    while (*wordptr != '\0') {
        
        // check which cell in the array should we consider
        unsigned int n = inalfabeto(wordptr);
            if (n>=ALPHABET) {return 1;} // ¿y después qué?
        
        // if the children doesn't exist, create it
        if ( nodeptr->alfabeto[n] != NULL ) {
            // allocate new node and check
            trie *newptr = malloc(sizeof(trie));
                if (newptr == NULL) {
                    destroy(root);
                    return 1;
                }
            // initalise values of the new node
            initnode(newptr);
            // insert the value in the given children
            nodeptr->alfabeto[n] = newptr;
        }
        nodeptr = nodeptr->alfabeto[n];
        wordptr++;        
    }
    nodeptr->isword = true;
    return 0;
}




/**
 * give in the word to look for, and the trie's root
 */
bool search(char *palabra, trie *root) {
    
    // aux pointers not to lose data just in case
    char *wordptr = palabra;
    trie *nodeptr = root;
    
    while (*wordptr != '\0') {
        
        // check the cell value
        int n = inalfabeto(wordptr);
            if (n>=ALPHABET) {return 0;} // ¿y después qué?
        
        // check if we can continue going through the trie
        if ( nodeptr->alfabeto[n] == NULL ) {
            return false;
        } else {
            nodeptr = nodeptr->alfabeto[n];
        }

        wordptr++;        
    }
    return nodeptr->isword;
}




/** destroy that shit! */
void destroy(trie *root) {
    trie *ptr = root;
    // aquí tengo que ir a por todos sus putos hijos...
    for (int i = 0; i < ALPHABET; i++) {
        if (ptr->alfabeto[i] != NULL) {
            destroy(ptr->alfabeto[i]);
        }
    }
    free(ptr);
}

unsigned int inalfabeto(char *value) {
    int letra;
    if (*value == '\'') {
        letra = ALPHABET - 1;
    } else if (isalpha(*value)) {
        letra = tolower(*value) - 'a';
    } else {
        letra = ALPHABET; // ojo, esta se va a salir del array!
    }
    return letra;
}
void initnode(trie *node) {
    node->isword = false;
    for (int i = 0; i < ALPHABET; i++) {
        node->alfabeto[i] = NULL;
    }
}

int main(void) {return 0;}
