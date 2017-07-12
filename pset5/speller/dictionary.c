/**
 * Implements a dictionary's functionality.
 */


#include "dictionary.h"
// personal definitions
// macro for Alphabet size
    #define ALPHABET 27
//trie node definition
    typedef struct _trie {
        bool isword; 
        struct _trie *alfabeto[ALPHABET];
    } trie;
// initialise THE MOTHER
    trie *ROOTOFTRIE = NULL;
// global variable for tracking dictionary size
    unsigned int word_count = 0;
// global boolean for tracking load/unload dictionary operations
    bool _loaded = false;
/** destroy that shit! */
    bool destroytrie(trie *ptr) {
        // aquí tengo que ir a por todos sus putos hijos...
        for (int i = 0; i < ALPHABET; i++) {
            if (ptr->alfabeto[i] != NULL) {
                destroytrie(ptr->alfabeto[i]);
            }
        } free(ptr);
        return true;
    }
/** extract its rationale number 
      (theoretically unnecesary extra steps here) */
    unsigned int inalfabeto(char *value) {
        if (*value == '\'') {
            return ALPHABET - 1;
        } else if (isalpha(*value)) {
            return tolower(*value) - 'a';
        }
        return ALPHABET;
    }
/** set everything to 0 and NULL on a new node */
    void initnode(trie *node) {
        node->isword = false;
        memset(node->alfabeto, '\0', ALPHABET);
    }
    trie *createtrie() {
        trie *trieptr = malloc(sizeof(trie));
            if (trieptr == NULL) {return NULL;}
        initnode(trieptr);
        return trieptr;
    }
// personal definitions

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    /* Take the ROOT and initialise it */
    ROOTOFTRIE = calloc(1,sizeof(trie));
        if (ROOTOFTRIE == NULL) {return false;}
    //ROOTOFTRIE->isword = false;
    //memset(ROOTOFTRIE->alfabeto, '\0', ALPHABET);
    
    /* Make a trasversal pointer at ROOT */
    trie *nodeptr = ROOTOFTRIE;
    
    /* prepare the variables here */
    char wordptr[LENGTH+1] = {'\0'};
    char aux = '\0';
    unsigned int i = 0;
    unsigned int n = 0;
    
    /* Open the dictionary */
    FILE * fp;
    fp = fopen(dictionary, "r");
        if (fp == NULL) {
            printf("Could not open the dictionary\n");
            return false;
        }
    
    /* Time to read into, string by string with fscanf */
    while ( fscanf(fp, "%s", wordptr) != EOF ){
        
        /* insert char by char until we reach the end of the word */
        aux = wordptr[i];
        while (aux != '\0') {
            
            /* check which cell in the array should we consider */
            if (aux == '\'') {
                n = ALPHABET - 1;
            } else {
                n = aux - 'a';
            }
            
            /** If it doesn't have a children, give it one */
            if ( nodeptr->alfabeto[n] == NULL ) {
                trie *zeronode = calloc(1,sizeof(trie));
                    if (zeronode == NULL)
                        {return false;}
                nodeptr->alfabeto[n] = zeronode;
            }
            
            nodeptr = nodeptr->alfabeto[n];
            i++;
            aux = wordptr[i];
        }
        nodeptr->isword = true;
        word_count++;
        nodeptr = ROOTOFTRIE;
        memset(wordptr, '\0', sizeof(wordptr));
        i=0;
    }
    fclose(fp);
    _loaded = true;
    return true;
}





/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    /* make a copy word of the original */
    char palabra[LENGTH+1];//= {'\0'};
    strcpy(palabra, word);

    // get the root of the dictionary
    trie *nodeptr = ROOTOFTRIE;
    int i = 0;
    
    while (palabra[i] != '\0') {
        
        // get the cell rationale
        int n = inalfabeto(&palabra[i]);
        
        // check if we can continue going through the trie
        if ( nodeptr->alfabeto[n] == NULL ) {
            return false;
        } else {
            nodeptr = nodeptr->alfabeto[n];
        }
        i++;
    }
    return nodeptr->isword;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (_loaded) {
        return word_count;
    } else {
        return 0;
    }
}


/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    _loaded = !destroytrie(ROOTOFTRIE);
    return !_loaded;
}
