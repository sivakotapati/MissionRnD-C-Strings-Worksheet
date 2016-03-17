/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

char **commonWords(char *, char *);
char ** gettingWords(char *, int);
int numberOfWords(char *);
int isSame(char *, char *);
void stringCopy(char *, char *);
int cw = 0;//common words

char ** commonWords(char *str1, char *str2){
	if (str1 ==NULL || str2 == NULL)//checking string address is  valid or not
		return NULL;

	int i, j, k, w1 = 0, w2 = 0, s = 0, e = 0, r = 0;
	char **s1, **s2, **s3;
	w1 = numberOfWords(str1);
	w2 = numberOfWords(str2);


	if (w1 == 0 || w2 == 0){
		//printf("no common words");
		return NULL;
	}

	//allocating memory
	//s1 is to store words from str1
	//s2 is to store words form str2
	//s3 is to store common words

	s1 = (char **)malloc(w1*sizeof(char *));
	for (i = 0; i < w1; i++){
		s1[i] = (char *)malloc(SIZE*sizeof(char));
	}

	s2 = (char **)malloc(w2*sizeof(char *));
	for (i = 0; i < w1; i++){
		s2[i] = (char *)malloc(SIZE*sizeof(char));
	}

	s3 = (char **)malloc(w1*sizeof(char *));
	for (i = 0; i < w1; i++){
		s3[i] = (char *)malloc(SIZE*sizeof(char));
	}



	//getting words from str1 into s1,from str2 into s2
	s1 = gettingWords(str1, w1);
	s2 = gettingWords(str2, w2);

	//checking for common words
	cw = 0;//count of common words
	for (i = 0; i < w1; i++){
		for (j = 0; j < w2; j++){
			if (isSame(s1[i], s2[j])){

				stringCopy(s3[cw++], s1[i]);
			}
		}
	}
	if (cw == 0){
		//printf("no common words");
		return NULL;
	}
	return s3;
}
char** gettingWords(char *str1, int w){
	int i, j, k, s, e, r;
	char **s1;

	s1 = (char **)malloc(w*sizeof(char *));
	for (i = 0; i < w; i++){
		s1[i] = (char *)malloc(SIZE*sizeof(char));
	}


	s = 0; r = 0;//r for rows
	for (i = 0; str1[i]; i++){
		//checking for space which means a word
		e = 0;
		if ((str1[i + 1] == ' ' || str1[i + 1] == '\0')){
			e = i;
		}

		//copying word into s1
		if (e != 0){
			for (j = s, k = 0; j <= e; j++){
				if (str1[j] != ' '){
					s1[r][k] = str1[j];
					k++;
				}
			}
			s1[r][k] = '\0';
			s = e + 2;
			if (k != 0) r++;
		}//if
	}
	return s1;
}
int numberOfWords(char *s){
	int i, w = 0;

	//finding no.of words in the string
	for (i = 0; s[i]; i++){
		if ((s[i + 1] == ' ' || s[i + 1] == '\0') && (i - 1) >= 0 && s[i] != ' '){
			++w;
		}
	}

	return w;
}
int isSame(char *a, char *b){
	//checking if two strings are same i.e words
	int i;
	for (i = 0; a[i] && b[i]; i++){
		if (a[i] != b[i]){
			return 0;
		}
	}
	if (a[i] == '\0'&&b[i] == '\0')
		return 1;
	return 0;

}


void stringCopy(char *d, char *s){
	int i;
	//copying string s to string d
	for (i = 0; s[i]; i++){
		d[i] = s[i];
	}
	d[i] = '\0';
}