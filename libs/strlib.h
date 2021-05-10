#ifndef STRLIB_H__
#define STRLIB_H__

/* copy all chars of a string up until a certain char is encountered */
char *cpy_until(char *dst, char *s, const char t);

/* replace first instance (or all instances) of specfic char with another char */
char *replace(char *s, const char orig, const char repl, int config);

/* search a string for a substring and return a pointer to after the substring */
char *strafter(const char *haystack, const char *needle);

#endif