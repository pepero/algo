/*
 * max_sum_subarray.cc
 *
 *  Created on: Jun 14, 2015
 *      Author: shao
 */
#include <stdlib.h>
#include <stdio.h>

/*
	problem:
	1) an array of integers, find the conseq subarray with max sum

*/


class Solution {
public:


    int maxSubArray(int num[], int start, int end, int* subMax, int* low, int* lowMax, int* high, int* highMax)
    {
    	if (start == end)
    	{
		  		*subMax = num[start];
		  		*low = start;
		  		*lowMax = num[start];
		  		*high = start;
		  		*highMax = num[start];
		  }
    	else
    	{
    		// devide into two groups

    		int subMaxLeft = 0;
    		int lowLeft = 0;
    		int lowMaxLeft = 0;
    		int highLeft = 0;
    		int highMaxLeft = 0;

    		int subMaxRight = 0;
    		int lowRight = 0;
    		int lowMaxRight = 0;
    		int highRight = 0;
    		int highMaxRight = 0;

  			int mid = (start + end)/2;
    		maxSubArray(num, start, mid, &subMaxLeft, &lowLeft, &lowMaxLeft, &highLeft, &highMaxLeft);
    		maxSubArray(num, mid+1, end, &subMaxRight, &lowRight, &lowMaxRight, &highRight, &highMaxRight);

    		int midMax = highMaxLeft + lowMaxRight;

            if (lowMaxRight> 0 && lowLeft == mid)
            {
                *low = lowRight;
                *lowMax = lowMaxLeft + lowMaxRight;
            }
            else{
                *low = lowLeft;
                *lowMax = lowMaxLeft;
            }

            if (highMaxLeft > 0 && highRight == mid+1)
            {
                *high = highLeft;
                *highMax = highMaxRight + highMaxLeft;
            }
            else{
                *high = highRight;
                *highMax = highMaxRight;
            }

    		*subMax = (subMaxLeft >= subMaxRight)? subMaxLeft: subMaxRight;
		  	*subMax = (midMax >= *subMax)? midMax : *subMax;
      }
    }

};

int main()
{
  int a[3] = {2, -4, 1};
  int d[8] = {1, -2, 3, 10, -4, 7, 2, -5};
  int b[8] = {2, 4, 1, 6, 7, 5, 20, 90};
  int c[16] = {2, 4, 1, 6, 7, 5, 20, 90, 3, 17, 10, 14, 50, 21, 39, 41};
  int e[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
  int f[5] = {2, 3, 4, 5, 7};
  Solution s;

  int subMax = 0;
  int low = 0;
  int high = 0;
  int lowMax= 0;
  int highMax = 0;
  int start = 0;
  int end = 4;

  s.maxSubArray(f, start, end, &subMax, &low, &high, &lowMax, &highMax);
  printf ("max is %d\n", subMax);
}




