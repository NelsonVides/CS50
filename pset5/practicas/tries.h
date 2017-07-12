/** TRIES, with the alphabet */

#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 45
#define ALPHABET 27
// node *first = NULL;

/** Defining the nodes */
typedef struct _trie trie;

/** trie *root = createtrie()
 * Create a new list altogether */
trie *createtrie();

/** root = insert(val,&root)
 * give in the value to insert, and the list's root
 */
int insert(char *value, trie *root);

/**
 * give in the value to look for, and the list's root
 */
bool search(char *palabra, trie *root);

/** destroy that shit! */
void destroy(trie *root);

unsigned int inalfabeto(char *value);
void initnode(trie *node);