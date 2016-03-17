/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char *, int, int);
void str_words_in_rev(char *input, int len){
	int i, s, e;
	//reversing the string
	reverse(input, 0, len - 1);

	s = 0;
	for (i = 0; input[i]; i++){
		//checking for space which indicates word
		if (input[i + 1] == ' ' || input[i + 1] == '\0'){
			e = i;
			reverse(input, s, e);//reversing word
			s = i + 2;
		}
	}
}
void reverse(char str[], int s, int e){
	//s is staring index,e is ending index

	int i, mid, j = 0;
	char t;

	mid = (s + e) / 2;
	for (i = s; i <= mid; i++){
		t = str[i];
		str[i] = str[e - j];
		str[e - j] = t;
		j++;
	}
}
