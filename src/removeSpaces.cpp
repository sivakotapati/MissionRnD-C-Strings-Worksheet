/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char removeSpaces(char *str) { 
	if (str == NULL)//checking for valid string(address)
		return '\0';
	int i, j;
	//start i,j at 0 
	//traverse through the string using i when str[i] is not space(' ')only then copy that element to str[j] and incremnet j
	//repeat till endo of string,j will be new length of string after removing spaces
	j= 0;
	for (i= 0; str[i]; i++){
		if (str[i]!= ' '){// check occurence of non space,then copy it to the new position
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	return '\0';
}