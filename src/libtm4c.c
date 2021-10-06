/******************************************************************************
*
*   Author: Taylor Gamache
*   Email: gamache.taylor@gmail.com
*   Created: Oct 6, 2021
*
*   Version: 0.1.2
*
*   License: MIT 2020
*
*   @name: libtm4c
*   @description: a simple lib for some basic functionality that the tiva lib doesn't provide or it overcomplicates
*
******************************************************************************/

/* *
 * gets:
 *
 * @info: read from stdin in the UART console until `size` is reached.
 * @info: similar to `gets` in 
 *
 * @returns: pointer to the start of `dst` or `NULL` is `s` is NULL.
 * */
char gets(char *s, int size)
{
	int i;
	char c;

	i = 0;
	while ((c = UARTgetc()) != '\r' && i < size) {
		UARTprintf("%c", c);
		*s++ = c;
		i++;
	}
	*s -= i;
	UARTprintf("\n");
	
	if (i == size) return NULL;

	return *s;
}


/* *
 * strncmp:
 *
 * @info: compare two strings.
 * @info: pretty much the smae as `strncmp` from libc.
 * 
 * @returns: 0 if strings are the same else a non-zero int.
 * */
int strncmp(const char *s1, const char *s2, int n)
{
  while(n > 0 && *s1 == *s2++) {
    if(*s1++ == '\0')
      return 0;
    n--;
  }
  return (n == 0 ? 0 : *s1 - *--s2);
}
