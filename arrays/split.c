#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **split(char *s, const char *delim)
{
    char **split_s;
    char *token, *string, *tofree;
    size_t s_len, split_len;
    int i;
    
    s_len = strlen(s);

    split_s = malloc(sizeof(char)*s_len*2);
    if (split_s == NULL) {
        fprintf(stderr, "split: could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    tofree = string = strdup(s);

    i = 0;
    while ((token = strsep(&string, delim)) != NULL) {
        // ignore white space after delimiter
        if (*token == ' ') memmove(token, token+1, strlen(token));
        *split_s = token;
        i++;
        split_s++;
    }
    *split_s = NULL;
    // bring pointer back
    split_s -= i;

    free(tofree);
    return split_s;
}


void print_vec(char **vec)
{
    //size_t length = sizeof(vec)/sizeof(vec[0]);
    //
    //printf("%zu\n", length);
    int i, len = 0;
    while (*vec) {
        printf("%s\n", *vec);
        len++;
        vec++;
    }
    // move pointer back to first string
    vec -= len;
}


int main(int argc, char **argv)
{
    char *str = "hello\nworld\nmy\nname\nis\ntaylor";
    char *s = "one, two, three";
  
    
    char **junk = split(s, ",");
    print_vec(junk);
    free(junk);

    char **p = split(str, "\n");
    print_vec(p);
    free(p);

    return 0;
}

