/**************************************************************************
*
*   Author: Taylor Gamache
*   Email: gamache.taylor@gmail.com
*
*   Version: 0.1.2
*
*   License: MIT 2020
*
*   @name: strlib
*   @description: a small string lib that has a few functions that `<string.h>` doesn't provide
*
***************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "strlib.h"


/* *
 * cpy_until:
 *
 * @desc: copy `s` into `dst` until `t` is encounted. if no `t`, entirety of `s` gets copied.
 *
 * @param: `dst` - string to copy `s` into.
 * @param: `*s` - string to be copied.
 * @param: `t` - `char` to copy until.
 *
 * @return: pointer to the start of `dst` or `NULL` is `s` is NULL.
 * */
char *cpy_until(char *dst, char *s, const char t)
{
    int i = 0;

	 if (s == NULL) return NULL;

    while (*s != t && *s != '\0') {
        *dst++ = *s++;
        i++;
    }
    *dst = '\0';
    s -= i;
    dst -= i;

    return dst;
}


/* *
 * replace:
 * 
 * @info: replaces `orig` with `repl` in `s`.
 * @info: config can be `FIRST` or `ALL`.
 * @info: `FIRST`: replace the first instance of `orig` with `repl`.
 * @info: `ALL`: replace all instances of `orig` with `repl`.
 *
 * @returns: a potiner to `s`. if not `FIRST` or `ALL` is supplied of config, or `orig` is not in `s`, pointer to `s` is returned
 * */
char *replace(char *s, const char orig, const char repl, int config)
{
    int i;

    if (config == FIRST) {
        i = 0;
        while (*s != orig && *s) {
            s++; i++;
        }
		if (*s == orig)
			*s = repl;
        s -= i;

        return s;

    } else if (config == ALL) {
        i = 0;
        while (*s) {
            if (*s == orig)
				*s = repl;
            s++;
            i++;
        }
        s -= i;

        return s;
    } 
    else return s;
}


/* *
 * lstrip:
 *
 * @info: strip pattern from start of string.
 *
 * @returns: pointer to location in `haystack` after `needle`. If not found, NULL.
 * */
char *strafter(const char *haystack, const char *needle)
{
    char *tmp;
    size_t len;

    if (haystack == NULL || needle == NULL)
        return NULL;

    if ((tmp = strstr(haystack, needle))) {
        len = strlen(needle);
        tmp += len;

        return tmp;
    }
    return NULL;
}


char *rstrip(char *s, char *pattern)
{
	char *tmp;
	size_t len;
	long end;

	if (s == NULL || pattern == NULL)
		return NULL;

	if ((tmp = strstr(s, pattern))) {
		end = (tmp - s) * sizeof(*s);
		s[end] = '\0';
	}
	return s;
}



/* *
 * between_two_ferns:
 *
 * @info: search `s` for `start`, if found, copy all chars until `end`.
 * @info: **note**: user must free after.
 * 
 * @returns: pointer to substring between `start` and `end`. if problem, return `s`.
 *
 * */
char *between_two_ferns(char *s, char *start, char *end)
{
    char *tmp, *end_tmp, *fern;
    size_t start_size, fern_size;

    if (!s) return NULL;

    if (!start || !end) return s;

    if ((tmp = strstr(s, start))) {
        start_size = strlen(start);
        tmp += start_size;
    } else {
        return NULL;
    }

    if ((end_tmp = strstr(tmp, end))) {
        fern_size = end_tmp - tmp;
    } else {
        return NULL;
    }

    fern = malloc(sizeof(char) * fern_size+1);
    if (fern == NULL) return NULL;

    size_t i = 0;
    while (i < fern_size) {
        *fern++ = *tmp++;
        i++;
    }
    *fern = '\0';
    fern -= i;

    return fern;
}


/**********  split  ***********/

// trim white space at beginning and end of string
static char *trim(char *str)
{
  char *end;
  
  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  if (*end != ' ') return str;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

/* *
 * split:
 *
 * @info: split a string into an array of strings based on delim (delimiters).
 * @info: preserves original string.
 *
 * @returns: pointer to an array of char pointers.
 * */
char **split(char *s, const char *delim)
{
    char **split_s;
    char *token, *tmp;
    size_t length;
    int i;

	if (s == NULL || strcmp(s, "")== 0) return NULL;

    length = strlen(s);

	tmp = malloc(sizeof(char)*length+1);
	if (tmp == NULL) return NULL;

	strcpy(tmp, s);
	tmp[length] = '\0';

    split_s = calloc(length*2, sizeof(char*));
    if (split_s == NULL) return NULL;

    i = 0;
    token = strtok(tmp, delim);
    while (token != NULL) {
		split_s[i] = trim(token);
        token = strtok(NULL, delim);
        i++;
    }
	if (i > 0)split_s[i] = NULL;
    return split_s;
}


/* *
 * print_arr:
 *
 * @info: sprint each string in an array of strinsg.
 * */
void print_arr(char **arr)
{
    int len = 0;
    while (*arr) {
        printf("%s\n", *arr);
        len++;
        arr++;
    }
    arr -= len;
}


/* *
 * arr_len:
 *
 * @returns: the number of strings in an array of strings.
 * */
int arr_len(char **arr)
{
    int l = 0;
    while(*arr) {
        arr++;
        l++;
    }
    arr -= l;
    return l;
}


/**
 * lstrip
 *
 * @desc: strip pattern from start of string
 *
 * @param: `s` - Original string.
 * @param: `pattern` - pattern to strip from `s`.
 *
 * */
char *lstrip(char *s, char *pattern)
{
	return strafter(s, pattern);
}
