/*
 * This is a binary tree program that takes a text file as an 
 * argument and puts each word into the tree then prints it.
 * 
 * Basically, give it a text file and it'll print out all
 * the words in alphabetical order
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct tnode {     // tree node
    char *word;             // points to the text
    struct tnode *left;     // left child
    struct tnode *right;    // right child
} tnode;

#define MAXWORD 50

tnode *addtree(tnode *, char *);
void treeprint(tnode *);
tnode *search(tnode *, char *);

int main(int argc, char **argv)
{
    FILE *fp;
    char word[MAXWORD];
    tnode *root;
    
    if (argc != 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return 1;
    }

    char *file = argv[1];

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("error: problem with file\n");
        return 1;
    }   

    root = NULL;
    while (fscanf(fp, "%s", word) != EOF)
        if (isalpha(word[0]))  // make sure it is a word
            root = addtree(root, word);
    treeprint(root);
    fclose(fp);

    printf("hello: %s\n", search(root, "hello")->word);
    printf("goodbye: %s\n", search(root, "goodbye")->word);
    printf("aloha: %s\n", search(root, "aloha")->word);

    return 0;
}

// addtree: add a node with w, at or below p
tnode *addtree(tnode *p, char *w)
{
    int cond;

    if (p == NULL) {    // if NULL then it found next empty branch
        p = (tnode *)malloc(sizeof(tnode));
        if (p == NULL) {
            fprintf(stderr, "error: memory full\n");
            exit(EXIT_FAILURE);
        }
        p->word = strdup(w);
        p->left = p->right = NULL; 

    // if root p is not NULL, keep going until we find the next place
    } else if ((cond = strcmp(w, p->word)) < 0)  
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}


// treeprint: in order print of tree
void treeprint(tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%s\n", p->word);
        treeprint(p->right);
    }
}

// search: search binary tree for char w
tnode *search(tnode *p, char *w)
{
    if (p->word == NULL || strcmp(w, p->word) == 0)
        return p;
    else if (strcmp(w, p->word) < 0)
        return search(p->left, w);
    else
        return search(p->right, w);
}