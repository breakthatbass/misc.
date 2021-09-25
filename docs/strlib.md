# strlib documentation
a small string lib that has a few functions that `<string.h>` doesn't provide  
#
```C
char *cpy_until(char *dst, char *s, const char t);
```
- copy `s` into `dst` until `t` is encountered.
- if `t` is never encountered, entirety of `s` gets copied.
- **returns** pointer to the start of `dst` or `NULL` is `s` is NULL.

<br>

```C
char *replace(char *s, const char orig, const char repl, int config);
```
- replaces `orig` with `repl` in `s`.
- config can be `FIRST` or `ALL`.
- `FIRST`: replace the first instance of `orig` with `repl`.
- `ALL`: replace all instances of `orig` with `repl`.
- **returns** a potiner to `s`. if not `FIRST` or `ALL` is supplied of config, or `orig` is not in `s`, pointer to `s` is returned

<br>

```C
char *strafter(const char *haystack, const char *needle);
```
- search `haystack` for `needle`.
- **returns** pointer to location in `haystack` after `needle`. If not found, NULL.

<br>

```C
char *between_two_ferns(char *s, char *start, char *end);
```
- search `s` for `start`, if found, copy all chars until `end`.
- **note**: user must free after.
- **returns** pointer to substring between `start` and `end`. if problem, return `s`.

<br>

```C
char **split(char *s, const char *delim);
```
- split a string into an array of strings based on delim (delimiters).
- preserves original string.
- **returns** pointer to an array of char pointers.

<br>

```C
int arr_len(char **arr);
```
- sprint each string in an array of strinsg.
- **returns** the number of strings in an array of strings.

<br>

