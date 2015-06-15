/*
 * itoa.cc
 *
 *  Created on: Jun 14, 2015
 *      Author: shao
 */

#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Solution{
public:
	// Converts an integer value to a null-terminated string
	// using the specified base and stores the result in the
	// array given by str parameter
	char* itoa (int value, char * str, int base );
	char* itoa_recursive(int value, char * str, int base);
};

char* Solution::itoa(int value, char * str, int base)
{
char *str_orgin = str;
	std::stack<int> s;
/*

	how to scan an integer?

	WRONG CODE!!

	int bitLength = sizeof(value) * 8;

 for (int i = 1; i < bitLength + 1; i++)
 {
   s.push(value % pow(10, i) + 48);
 }
*/


 int i = abs(value);
 while (i != 0)
	{
     s.push(i % base + 48);
     i = (i - i % base) / base;
	}

	if (value > 0) *str = '+';
	else if (value == 0) *str = '0';
	else *str = '-';

	while (!s.empty())
	{
	   int j = s.top();
	   s.pop();
	   str++;
	   *str = j;
	}
	str++;
	*str = '\0';
	return str_orgin;
}

/*
char* Solution::itoa_recursive(int value, char * str, int base)
{
 static bool finished = false;
 if (value == 0 && !finished)
 {
         *str = '0';
         finished = true;
 }

 // positive integer
 while (value > 0)
 {
         int i = value % base;
         int j = (value - i) / base;
         if (j == 0)
         {
                 finished = true;
                 str++;
                 *str = i + 48;
                 return str;
         }
         itoa_recursive (j, str, base);
         str++;
         *str = i + 48;
 }

 // negative integer
 while (value < 0)
 {
         int i = value % base;
         int j = (value + i) / base;
         if (j == 0){
             *str = '-';
             str++;
                         *str = i + 48;
                                                 return str;
         }
         itoa_recursive (j, str, base);
         str++;
         *str = i + 48;

 }

 // terminator of string
 if (finished)
 {
         str++;
         *str = '\0';
         return str;
 }
}
*/

char* Solution::itoa_recursive(int value, char * str, int base)
{
	static bool finished = false;
	static int iter = 0;
 static int counter = 0;
	if (value == 0)
	{
		finished = true;
		return str;
	}

	// positive integer
	if (value > 0)
	{
		int i = value % base;
		int j = (value - i) / base;
		iter++;
		if (j == 0){
		    *str = '+';
		}
		str = itoa_recursive (j, str, base);
		*(str+1) = i + 48;
		iter--;
 	return str+1;
	}

	// negative integer
	if (value < 0)
	{
		int i = value % base;
		int j = (value + i) / base;
		if (j == 0){
		    *str = '-';
		}
		itoa_recursive (j, str, base);
		str++;
		*str = i + 48;
	}

		// terminator of string
	if (finished && iter==0)
	{

		*(str+counter+1) = '\0';
		return str;
	}
}


int main()
{
	Solution s;
	char str[50] = {0};
	char str_recur[50] = {0};
	printf ("str is %s \n", s.itoa(17, str, 10));
	if (strcmp(str, "+17") != 0) printf ("test failed with itoa\n");
	printf ("str is %s \n", str);

	s.itoa_recursive(17, str_recur, 10);
	printf ("str_rec is %s \n", str_recur);
	if (strcmp(str_recur, "+17") != 0) printf ("test failed with itoa_recur\n");


	// if (s.itoa(17, str, 10) != "+17") printf ("test failed with itoa\n");
	//if (s.itoa_recursive(17, str, 10) != "17") printf ("test failed with itoa_recursive\n");
}




