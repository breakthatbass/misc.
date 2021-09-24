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
*   @description: a small string lib that has a few functions that `<string.h>`
*   doesn't provide
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
 * @info:  
 *	DESCRIPTION:
 *		replace char orig with char repl in string s. Config can be FIRST or ALL.
 *		FIRST: replace the first instance of char orig and char repl.
 *		ALL: replace all instances of char orig with char repl.
 *
 *	RETURN VALUE:
 *		Returns a pointer to string s. If something other than FIRST or ALL is
 *		supplied for config, it simply returns a pointer to s without doing
 *		anything. Also, if char orig is not found in s, it also returns a
 *		pointer to s.
 *
 *      enum config { FIRST = 1, ALL = 2 };
 * */
char *replace(char *s, const char orig, const char repl, int config);


/* *
 *	strafter:
 *
 * DESCRIPTION:
 *		strafter searches string haystack for substring needle. if found, it returns
 *		a pointer to the string haystack after needle. similar to strstr.
 *
 *	RETURN VALUE:
 *		returns a pointer to location in haystack after substring needle. If
 *		needle is not in haystack, it returns NULL.
 *
 * */
char *strafter(const char *haystack, const char *needle);



/* *
 *	between_two_ferns(char *s, char *start, char *end)
 *
 * DESCRIPTION:
 *		search string s for strat, if it exists, copy all characters until
 *      end is encounted.
 *
 *	RETURN VALUE:
 *		returns a pointer to the string between start and end.
 *      if only one of start or end exist, or neither exist, return s.
 *      user must free.
 *
 * */
char *between_two_ferns(char *s, char *start, char *end);


#endif
