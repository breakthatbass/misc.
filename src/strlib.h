/******************************************************************************
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
******************************************************************************/

#ifndef STRLIB_H__
#define STRLIB_H__


/* *
 * cpy_until:
 *
 * @info: copy `s` into `dst` until `t` is encountered.
 * @info: if `t` is never encountered, entirety of `s` gets copied.
 *
 * @returns: pointer to the start of `dst` or `NULL` is `s` is NULL.
 * */
char *cpy_until(char *dst, char *s, const char t);


enum config { FIRST = 1, ALL = 2 };
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
char *replace(char *s, const char orig, const char repl, int config);


/* *
 * strafter:
 *
 * @info: search `haystack` for `needle`.
 *
 * @returns: pointer to location in `haystack` after `needle`. If not found, NULL.
 * */
char *strafter(const char *haystack, const char *needle);



/* *
 * between_two_ferns:
 *
 * @info: search `s` for `start`, if found, copy all chars until `end`.
 * @info: **note**: user must free after.
 * 
 * @returns: pointer to substring between `start` and `end`. if problem, return `s`.
 *
 * */
char *between_two_ferns(char *s, char *start, char *end);


/**********  split  ***********/

/* *
 * split:
 *
 * @info: split a string into an array of strings based on delim (delimiters).
 * @info: preserves original string.
 *
 * @returns: pointer to an array of char pointers.
 * */
char **split(char *s, const char *delim);


/* *
 * print_arr:
 *
 * @info: print each string in an array of string.
 * */
void print_arr(char **arr);



/* *
 * arr_len:
 *
 * @returns: the number of strings in an array of strings.
 * */
int arr_len(char **arr);


/**
 * lstrip
 * */
char *rstrip(char *s, char *pattern);


#endif
