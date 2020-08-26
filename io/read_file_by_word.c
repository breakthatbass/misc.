/*
 * This program reads a file supplied by an argument
 * and prints each word on a seperate line.
 */

#include <stdio.h>

#define MAXWORD 50

int main(int argc, char **argv)
{
    FILE *fp;
    char word[MAXWORD];
    
    char *file = argv[1];

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("error: problem with file\n");
        return 1;
    }   
    
    // crux of program here
    // fscanf reads from 'fp', read a full strinf with '%s'
    // and puts it into the 'word' array which 
    // gets overwritten in each iteration
    while (fscanf(fp, "%s", word) != EOF)
         printf("%s\n", word);

    fclose(fp);
}
