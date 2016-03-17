/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
char KthIndexFromEnd(char *str, int  K) {
	if (str == NULL || K < 0)
		return '\0';
	int i,len;

	//finding length of the string
	for (i = 0; str[i]; i++);
	len = i;

	//returning last kth element from last if k<len
	if (K < len)
		return str[len - 1 - K];

	return '\0';
}