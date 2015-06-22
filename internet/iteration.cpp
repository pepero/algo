/*	
 problem:
 in iteration:
 1) copy a string
 2) reverse a string 
*/
#include <stdio.h>

class Solution {

public:
  void printStr_iter(char* str, const char * str_src){
    if (*str_src) {
      *str = *str_src;
      str++; 
      str_src++;
      printStr_iter(str, str_src);
    }
  }

   char* reverseStr_iter(char* str, const char * str_src){
    if (*str_src) {
      str = reverseStr_iter(str, str_src+1);
      *str = *str_src;
      return str+1;
    }else{return str;}
  }
};

int main()
{
	Solution s;
	char str[50] = {0};
	char str_recur[50] = {0};
 char* str_1 = "test";
 char* str_to_reverse = "test";
 s.printStr_iter(str, str_1);
 printf("result is %s \n", str);
 s.reverseStr_iter(str_recur, str_to_reverse);
 printf("result reverse is %s \n", str_recur);
}

