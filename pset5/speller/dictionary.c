/**
 * Implements a dictionary's functionality.
 */

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "dictionary.h"
#define ALPHABET 27

typedef struct node
{
    bool word;
    struct node* children[ALPHABET];
} node;

void unloader(node* current);
node* root;

unsigned int dictionary_size =0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node* cursor = root;
    
    for (int i = 0, n = strlen(word); i < n; i++ )
    {
        int index = (word[i] == '\'' ) ? ALPHABET -1: tolower(word[i]) - 'a';
        
        if (cursor->children[index] == NULL )
        {
            return false;
        }
        else
        {
            cursor = cursor->children[index];
        }
         
    }
    
    return cursor->word;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    root = calloc(1, sizeof(node));
    if (root == NULL)
    {
        fclose(file);
        return false;
    }
    
    node* cursor = root;
    for (int c = fgetc(file); c != EOF; c = fgetc(file) )
    {
        if (c != '\n')
        {
            int index = (c == '\'' ) ? ALPHABET -1 : c - 'a';
            if (cursor->children[index] == NULL)
            {
                cursor->children[index] = calloc(1, sizeof(node));
                if (cursor->children[index] == NULL)
                {
                    unload();
                    fclose(file);
                    return false;
                }
            }
            
            cursor = cursor->children[index];
        }
        else 
        {
            cursor->word = true;
            cursor = root;
            dictionary_size ++;
        }
    }
    if (ferror(file))
    {
        unload();
        fclose(file);
        return false;
        
    }
    fclose(file);
     
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return dictionary_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    unloader(root);
    return true;
}



void unloader (node* current)
{
    for (int i=0; i<ALPHABET; i++)
    {
        if (current->children[i] !=NULL)
        {
            unloader(current->children[i]);
        }
    }
    free(current);
}