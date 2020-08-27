/*
 * This is a binary tree program that takes a text file as an 
 * argument and puts each number into the tree then prints it.
 * 
 * Basically, give it a text file and it'll print out all
 * the numbers in numerical roder
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct tnode {     // tree node
    int num;                // number
    struct tnode *left;     // left child
    struct tnode *right;    // right child
} tnode;

#define MAXLEN 50

tnode *addtree(tnode *, int);
void treeprint(tnode *);
tnode *search(tnode *, int);

int main(int argc, char **argv)
{
    FILE *fp;
    char num[MAXLEN]; 
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
 
    while (fgets(num, MAXLEN, fp)) {
        if (isdigit(num[0]))  // make sure it is a number
            root = addtree(root, atoi(num));
    }

    treeprint(root);
    fclose(fp);

    if (search(root, 64315) == NULL) 
        printf("not found\n");
    else
        printf("found\n");
    return 0;
}


// addtree: add a node with n at or below p
tnode *addtree(tnode *p, int n)
{
    int cond;

    if (p == NULL) {    // if NULL then it found next empty branch
        p = (tnode *)malloc(sizeof(tnode));
        if (p == NULL) {
            fprintf(stderr, "error: memory full\n");
            exit(EXIT_FAILURE);
        }
        p->num = n;
        p->left = p->right = NULL; 

    } else if (n < p->num)  
        p->left = addtree(p->left, n);
    else
        p->right = addtree(p->right, n);
    return p;
}

// treeprint: in order print of tree
void treeprint(tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%d\n", p->num);
        treeprint(p->right);
    }
}

// search: search binary tree for int n
tnode *search(tnode *p, int n)
{
    while (p != NULL) {
        if (n < p->num)
            p = p->left;
        else if (n > p->num)
            p = p->right;
        else
            return p;
    }
    return NULL;
}