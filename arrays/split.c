#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **split(char *s, const char *delim)
{
    char **split_s;
    char *token, *string, *tofree;
    size_t len;
    int i, l;
    
    len = strlen(s);
    
    split_s = malloc(sizeof(char)*len*2);
    if (split_s == NULL) {
        fprintf(stderr, "split: could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    tofree = string = strdup(s);

    i = 0;
    while ((token = strsep(&string, delim)) != NULL) {
        *split_s = token;
        i++;
        split_s++;
    }
    // bring pointer back
    split_s -= i;
    l = i;

    free(tofree);
    return split_s;
}


void print_vec(char **vec)
{
    int i, len = 0;
    while (*vec) {
        printf("%s\n", *vec);
        len++;
        vec++;
    }
    vec -= len;
}


int main(int argc, char **argv)
{
    char *str = "hello\nworld\nmy\nname\nis\ntaylor\n";
    char d = '\n';
    char **p = split(str, "\n");

    print_vec(p);
    free(p);

    return 0;
}

