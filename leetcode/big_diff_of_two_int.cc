/*
 * big_diff_of_two_int.cc
 *
 *  Created on: Jun 14, 2015
 *      Author: shao
 */

#include <stdlib.h>
#include <stdio.h>

/*
	problem:
	1) an array of integers, find the pair, left minus right, with biggest difference

*/


class Solution {
public:
		int diff;
  	int max;
  	int min;

		/*

		PROBLEMS: should not define member variables for these subMax and subMin, otherwise they will be overwritten.
		they should just be the temporary variables created and released on stack

    int findPair(int num[], int size, int* subMax, int* subMin)
    {
    	if (size == 2)
    	{
    			if ((num[0]-num[1]) > diff)
		  		{
		  			diff = num[0]-num[1];
		  			max = num[0];
		  			min = num[1];
		  		}
		  		*subMax = (num[0] >= num[1])? num[0] : num[1];
		  		*subMin = (num[0] <= num[1])? num[0] : num[1];
		  }
    	else
    	{
    		// devide into two groups
    		int subsize = size/2;
    		findPair(num, subsize, subMaxLeft, subMinLeft);
    		findPair(num+subsize, subsize, subMaxRight, subMinRight);

    		if ((*subMaxLeft-*subMinRight) > diff)
    		{
    			diff = *subMaxLeft-*subMinRight;
    			max = *subMaxLeft;
    			min = *subMinRight;
    			printf ("max %d and min %d come from two different groups\n", max, min);
    		}
    		*subMax = (*subMaxLeft >= *subMaxRight)? *subMaxLeft : *subMaxRight;
    		printf ("within the size %d, subMaxLeft %d, and subMaxRight %d \n", size, *subMaxLeft, *subMaxRight);
		  	*subMin = (*subMinLeft <= *subMinRight)? *subMinLeft : *subMinRight;
    		printf ("within the size %d, subMinLeft %d, and subMinRight %d \n", size, *subMinLeft, *subMinRight);
      }
    }
    */

    /*

    PROBLEM: only work for the size of 2, 4, 8, 16, etc.

    int findPair_right(int num[], int size, int* subMax, int* subMin)
    {
    	if (size == 2)
    	{
    			if ((num[0]-num[1]) > diff)
		  		{
		  			diff = num[0]-num[1];
		  			max = num[0];
		  			min = num[1];
		  		}
		  		*subMax = (num[0] >= num[1])? num[0] : num[1];
		  		*subMin = (num[0] <= num[1])? num[0] : num[1];
		  }
    	else
    	{
    		// devide into two groups
    		int subsize = size/2;
  			int subMaxLeft_r 	= 0;
  			int subMaxRight_r = 0;
  			int subMinLeft_r  = 0;
  			int subMinRight_r = 0;
    		findPair_right(num, subsize, &subMaxLeft_r , &subMinLeft_r );
    		findPair_right(num+subsize, subsize, &subMaxRight_r , &subMinRight_r );

    		if ((subMaxLeft_r-subMinRight_r) > diff)
    		{
    			diff = subMaxLeft_r-subMinRight_r;
    			max = subMaxLeft_r;
    			min = subMinRight_r;
    			printf ("max %d and min %d come from two different groups\n", max, min);
    		}
    		*subMax = (subMaxLeft_r >= subMaxRight_r)? subMaxLeft_r : subMaxRight_r;
    		printf ("within the size %d, subMaxLeft %d, and subMaxRight %d \n", size, subMaxLeft_r, subMaxRight_r);
		  	*subMin = (subMinLeft_r <= subMinRight_r)? subMinLeft_r : subMinRight_r;
    		printf ("within the size %d, subMinLeft %d, and subMinRight %d \n", size, subMinLeft_r, subMinRight_r);
      }
    }

    */

    /*

    devide and conquer: how to devide?
    1. size/2




    */

    /*

    ERROR:

    int findPair_right(int num[], int size, int* subMax, int* subMin)
    {
    	if (size == 1)
    	{
		  		*subMax = num[0];
		  		*subMin = num[0];
		  }

    	if (size == 2)
    	{
    			if ((num[0]-num[1]) > diff)
		  		{
		  			diff = num[0]-num[1];
		  			max = num[0];
		  			min = num[1];
		  		}
		  		*subMax = (num[0] >= num[1])? num[0] : num[1];
		  		*subMin = (num[0] <= num[1])? num[0] : num[1];
		  }
    	else
    	{
    		// devide into two groups
    		int subsize = size/2;
  			int subMaxLeft_r 	= 0;
  			int subMaxRight_r = 0;
  			int subMinLeft_r  = 0;
  			int subMinRight_r = 0;
    		findPair_right(num, subsize, &subMaxLeft_r , &subMinLeft_r );
    		findPair_right(num+subsize, size-subsize, &subMaxRight_r , &subMinRight_r );

    		if ((subMaxLeft_r-subMinRight_r) > diff)
    		{
    			diff = subMaxLeft_r-subMinRight_r;
    			max = subMaxLeft_r;
    			min = subMinRight_r;
    			printf ("max %d and min %d come from two different groups\n", max, min);
    		}
    		*subMax = (subMaxLeft_r >= subMaxRight_r)? subMaxLeft_r : subMaxRight_r;
    		printf ("within the size %d, subMaxLeft %d, and subMaxRight %d \n", size, subMaxLeft_r, subMaxRight_r);
		  	*subMin = (subMinLeft_r <= subMinRight_r)? subMinLeft_r : subMinRight_r;
    		printf ("within the size %d, subMinLeft %d, and subMinRight %d \n", size, subMinLeft_r, subMinRight_r);
      }
    }
    */

    int findPair_right(int num[], int size, int* subMax, int* subMin)
    {
    	if (size == 1)
    	{
		  		*subMax = num[0];
		  		*subMin = num[0];
		  }

		  /*
    	else if (size == 2)
    	{
    			if ((num[0]-num[1]) > diff)
		  		{
		  			diff = num[0]-num[1];
		  			max = num[0];
		  			min = num[1];
		  		}
		  		*subMax = (num[0] >= num[1])? num[0] : num[1];
		  		*subMin = (num[0] <= num[1])? num[0] : num[1];
		  }
		  */
    	else
    	{
    		// devide into two groups
    		int subsize = size/2;
  			int subMaxLeft_r 	= 0;
  			int subMaxRight_r = 0;
  			int subMinLeft_r  = 0;
  			int subMinRight_r = 0;
    		findPair_right(num, subsize, &subMaxLeft_r , &subMinLeft_r );
    		findPair_right(num+subsize, size-subsize, &subMaxRight_r , &subMinRight_r );

    		if ((subMaxLeft_r-subMinRight_r) > diff)
    		{
    			diff = subMaxLeft_r-subMinRight_r;
    			max = subMaxLeft_r;
    			min = subMinRight_r;
    			printf ("max %d and min %d come from two different groups\n", max, min);
    		}
    		*subMax = (subMaxLeft_r >= subMaxRight_r)? subMaxLeft_r : subMaxRight_r;
    		printf ("within the size %d, subMaxLeft %d, and subMaxRight %d \n", size, subMaxLeft_r, subMaxRight_r);
		  	*subMin = (subMinLeft_r <= subMinRight_r)? subMinLeft_r : subMinRight_r;
    		printf ("within the size %d, subMinLeft %d, and subMinRight %d \n", size, subMinLeft_r, subMinRight_r);
      }
    }

};

int main()
{
  int a[3] = {2, 4, 1};
  int b[8] = {2, 4, 1, 6, 7, 5, 20, 90};
  int c[16] = {2, 4, 1, 6, 7, 5, 20, 90, 3, 17, 10, 14, 50, 21, 39, 41};
  Solution s;
  s.diff = 0;
  s.max = 0;
  s.min = 0;

  int subMax = 0;
  int subMin = 0;

  s.findPair_right(c, 16, &subMax, &subMin);
  printf ("max is %d, min is %d, maxG is %d, minG is %d \n", s.max, s.min, subMax, subMin);
}


