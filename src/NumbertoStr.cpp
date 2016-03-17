/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include<stdio.h>
void number_to_str(float, char *, int);
int int_to_string(int, char *, int);
void reverse_string(char *, int, int);

void number_to_str(float number, char *str, int afterdecimal){
	int ip, n, i, m, j, last_pos;
	float fp;

	if (number < 0){
		ip = -1 * (int)number;
		fp = -1 * number - ip;
	}
	else{
		ip = (int)number;
		fp = number - ip;
	}

	i = 0;
	//if number is negative then put "-"sign at beginning
	if (number<0){
		str[i] = '-';
		i++;
	}

	n = ip;
	last_pos = int_to_string(n, str, i);
	//n:integer part,str:string,i:staring pos,last_pos will receive the last postion of the string

	
	if (afterdecimal > 0){
		j = 0;
		//converting fractional part to integer
		while (j < afterdecimal){ 
			fp = fp * 10;
			j++;
		}
		m = (int)fp;

		str[last_pos] = '.';
		str[++last_pos] = '\0';
		last_pos = int_to_string(m, str, last_pos);//m is number,a is string,last_post is from which pos next element add to strng

		str[last_pos + afterdecimal] = '\0';

	}//if
}
int int_to_string(int n, char *str, int i)
{
	//this function returns the last position of the string
	int rem = 0, s = i;

	//converting integer part to string
	while (n != 0){
		rem = n % 10;
		str[i] = rem + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';

	//reversing str to get integer part correct
	reverse_string(str, s, i - 1);//s is strating index,i-1 last index

	return i;

}
void reverse_string(char *str, int s, int e){
	//s is staring index,e is ending index
	int i, mid, k;
	char temp;
	mid = (s + e) / 2;

	k = 0;
	for (i = s; i <= mid; i++, k++){
		temp = str[i];
		str[i] = str[e - k];
		str[e - k] = temp;
	}

}
