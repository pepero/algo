#include <stdlib.h>
#include <stdio.h>

class Solution {

public:
    char* cur_str;
    char  empty_sp;
    // char* dissector = [' ', ',', ';'];
    int num;
    bool prev_is_operator;
    int prefixExpr()
    {
      while (*cur_str !='\0')
      {
        // printf("incoming str is %s \n", cur_str);
        if (*cur_str == '+' || *cur_str == '-'
         || *cur_str == '*' || *cur_str == '/')
        {
          char opertor = *cur_str;
          cur_str++;
          int operand_1 = prefixExpr ();
          // printf("index for operand2 is %d \n", index);
          int operand_2 = prefixExpr ();
          return cal (opertor, operand_1, operand_2);
        }
        if ('0' <= *cur_str && *cur_str <= '9')
        {
          // printf("it is an operand %d\n", *cur_str - 48);
          int operand = *cur_str - 48;
          cur_str++;
          return operand;
        }
      }
    }

    int cal (char opertor, int opertand_1, int opertand_2)
    {
      switch (opertor) {
      case '+':
        // printf("opertand_1 %d + opertand_2 %d \n", opertand_1, opertand_2);
        return opertand_1 + opertand_2;
      case '-':
        // printf("- is %d \n", opertand_1 - opertand_2);
        return opertand_1 - opertand_2;
      case '*':
        // printf("* is %d \n", opertand_1 * opertand_2);
        return opertand_1 * opertand_2;
      case '/': return opertand_1 / opertand_2;
        // printf("/ is %d \n", opertand_1 / opertand_2);
        return opertand_1 / opertand_2;
      default:
        printf ("Error, bad input, quitting\n");
        break;
      }
    }

    int prefixExpr_dissector()
    {
      while (*cur_str !='\0')
      {
        // printf("incoming str is %s \n", cur_str);
        if (*cur_str == '+' || *cur_str == '-'
         || *cur_str == '*' || *cur_str == '/')
        {
          char opertor = *cur_str;
          cur_str++;
          int operand_1 = prefixExpr_dissector ();
          // printf("index for operand2 is %d \n", index);
          int operand_2 = prefixExpr_dissector ();
          return cal (opertor, operand_1, operand_2);
        }
        if ('0' <= *cur_str && *cur_str <= '9')
        {
          // printf("it is an operand %d\n", *cur_str - 48);
          num = 0;
          do
          {
            int operand = *cur_str - 48;
            num = num*10+operand;
            cur_str++;
          }
          while (*cur_str !=' ' && *cur_str !='\0');
          return num;
        }
        if (empty_sp == *cur_str)
        {
          cur_str++;
          return prefixExpr_dissector ();
        }
      }
    }
};

int main()
{
  Solution s;
  s.empty_sp = ' ';
  s.cur_str = "+27";
  if (s.prefixExpr() != 9)
    printf("test fail with '+27' \n");
  s.cur_str = "++277";
  if (s.prefixExpr() != 16)
    printf("test fail with '++277' \n");
  s.cur_str = "+2++277";
  if (s.prefixExpr() != 18)
    printf("test fail with '+2++277' \n");
  s.cur_str = "+++2772";
  if (s.prefixExpr() != 18)
    printf("test fail with '+++2772' \n");
  s.cur_str = "-27";
  if (s.prefixExpr() != -5)
    printf("test fail with '-27' \n");
  s.cur_str = "*27";
  if (s.prefixExpr() != 14)
    printf("test fail with '*27' \n");
  s.cur_str = "/27";
  if (s.prefixExpr() != 2/7)
    printf("test fail with '/27' \n");

  s.cur_str = "+ 20 7 ";
  if (s.prefixExpr_dissector() != 27)
    printf("test fail with '+ 20 7' \n");
  s.cur_str = "* / + 27 7 2 2";
  if (s.prefixExpr_dissector() != 34)
    printf("test fail with '+ 20 7' \n");
}
