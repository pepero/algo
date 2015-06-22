#include <stdlib.h>
#include <stdio.h>

/*
	problem:
	1) an array of integers contain 1 integer occures once, other all occur 2 times
	2) an array of integers contain 2 integers occure once, other all occur 2 times
	3) an array of integers contain 3 integers occure once, other all occur 2 times

	find the integers, in linear time and constant space

*/


class Solution {
  int a[100];
  int b[101];
	int c[101];

public:

    int buildArray_1()
    {
      for (int i=0; i < 50; i++) {
        b[2*i] = i+1;
        b[2*i+1] = i+1;
      }
      b[100] = 99;
    }
    int oneOccur1_recur()
    {
      static int i = 100;
      if (i > 0) {
        int t = b[i];
        i--;
        return t^oneOccur1_recur();
      }
      if (i == 0) {
        return b[0];
      }
    }

    int buildArray_2()
    {
      for (int i=0; i < 50; i++) {
        a[2*i] = i+1;
        a[2*i+1] = i+1;
      }
      a[50] = 99;
    }
    int twoOccur1_Other2()
    {
      int sum = 0;
			int sum_l = 0;
			int sum_r = 0;

      for (int i = 0; i < 100; i++) {
        sum = sum^a[i];
      }

      // find first bit non-zero in sum
			int bit_size = sizeof (sum)*8;
			int diff = 0;
      for (int i = 0; i < bit_size; i++) {
				diff = sum & (1<<i);
				if (diff) break;
			}
			for (int i = 0; i < 100; i++) {
        if (a[i] & diff) sum_l = sum_l^a[i];
				else sum_r = sum_r^a[i];
      }
			printf ("result of 2 element occure once are %d, %d\n", sum_l, sum_r);
    }

		int buildArray_3()
    {
      for (int i=0; i < 49; i++) {
        c[2*i] = i+1;
        c[2*i+1] = i+1;
      }
			c[98] = 98;
			c[99] = 99;
      c[100] = 101;
    }

		int lastBitOne(int num)
		{
           return num & ~(num - 1);
		}

    int threeOccur1_Other2()
    {
			int sum_all = 0;
		  int sum_lastbit = 0;

			int sum_l = 0;
			int sum_r = 0;

			int sum_2nd = 0;
			int sum_3rd = 0;

			for (int i = 0; i < 101; i++){
				sum_all = sum_all^c[i];
			}

			// find last non-zero bit
			for (int i = 0; i < 101; i++){
				sum_lastbit = sum_lastbit ^ lastBitOne(sum_all^c[i]);
			}

			// find the bit non-zero in sum_lastbit
			int bit_size_2 = sizeof (sum_lastbit)*8;
			int diff = 0;
      for (int i = 0; i < bit_size_2; i++) {
				diff = sum_lastbit & (1<<i);
				if (diff) break;
			}
			// separate according to this bit
			for (int i = 0; i < 101; i++) {
        if (c[i] & diff) sum_l = sum_l^c[i];
				else sum_r = sum_r^c[i];
      }
			printf ("result of 3 element occure once. first 1 element is %d\n", sum_r);

			// find first bit non-zero in sum_l, which contain two other elements
			bit_size_2 = sizeof (sum_l)*8;
			diff = 0;
      for (int i = 0; i < bit_size_2; i++) {
				diff = sum_l & (1<<i);
				if (diff) break;
			}
			// separate according to this last bit
			for (int i = 0; i < 101; i++) {
				if (c[i] == sum_r) continue;
        if (c[i] & diff) sum_2nd = sum_2nd^c[i];
				else sum_3rd = sum_3rd^c[i];
      }
			printf ("result of 3 element occure once. other 2 elements are %d, %d\n", sum_2nd, sum_3rd);
    }
};

int main()
{
  Solution s;
  s.buildArray_1();
  int result = s.oneOccur1_recur();
  printf("result of one element occure once is %d\n", result);
  s.buildArray_2();
  s.twoOccur1_Other2();
  s.buildArray_3();
  s.threeOccur1_Other2();
}
