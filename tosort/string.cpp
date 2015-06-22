/** 
 * string related functions in c std lib by P.J.Plauger
 */

#include "stdio.h"

class Solution {
public:

//-------------------------------------------------------------------
/*
    void* memcpy_1(void *s1, const void *s2, int n)
    {                                              
        while(n--) {                               
            *s1++ = *s2++;                         
        }                                          
        return s1;                                 
    }                                              
*/

    void* memcpy_2(void *s1, const void *s2, int n)
    {
        char* s1_ = (char*) s1;
        char* s2_ = (char*) s2;

        while(n--) {
            *s1_++ = *s2_++;
        }
        return s1;
    }
/*
    void* memcpy_0(void *s1, const void *s2, int n)
    {                                              
        char* su1                 
        const char* su2                     
 
        for(su1 = s1, su2 = s2; 0 < n; su1++, su2++, n--)
            *su1 = *su2;
        return s1;                                 
    }                                              
*/
//-------------------------------------------------------------------

/*
    void* memmove_1(void *s1, const void *s2, int n)
    {                                               
        if(s1+n<s2 || s2+n<s1) {                    
            return memcpy(s1, s2, n);               
        } else {                                    
                                                    
        }                                           
    }                                               
*/

    void* memmove_2(void* dst, const void* src, int n)
    {
        char* dst1 = dst;
        const char* src1 = src;

        if(src1 < dst1 && dst1 < src1+n) {
            for(; 0 < n; n--) {
                *(dst+n-1) = *(src1 + n-1); 
            }
        }
        else{
            for(int i=0; i<n; i++) {
                *(dst1+i) = *(src1+i);      
            }
        }
        return dst;
    }

    void* memmove_0(void* dst, const void* src, int n)
    {
        char* sc1 = dst;
        const char* sc2 = src;

        if (sc2 < sc1 && sc1 < sc2 + n) 
            for(sc2 += n, sc1 += n; 0 < n; --n) 
                *--sc1 = *--sc2; /* copy backwards */
        else
            for(; 0 < n; n--) 
                *sc1++ = *sc2++; /* copy forwards */
            
        return dst;
    }


};

int main(){
    Solution s;

/*
    deprecated warnings if
    char* s1 = "abcd";    
*/

    char s1[] = "abcd";
    char s2[] = "acde";
    s.memcpy_2(s1, s2, 4);
    printf("s1 is %s, s2 is %s \n", s1, s2);
}
