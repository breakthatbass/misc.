#include <stdio.h>
#include <ctype.h>
#include <string.h>


struct tnode {        // tree node
    char *word;             // points to the text
    int count;              // number of occurances
    struct tnode *left;     // left child
    struct tnode *rightl    // right child
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);


// word frequency count
int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}



