/*	
 problem:
 given a decimal integer:
 1) the most significant decimal digit
 2) 
 2) whether it is palindrome number, with no extra space use
*/

class Solution {
public:

    int msddInt(int i){
        int j=0;
        for (j=1; j<i; j*=10);
        return i*10/j; 
    }

    int msddInt2(int i){
        int j = 1;
        while((i/j)>10) {
            j*=10;
        }
        return j; 
    }

    int reverseInt(int i){


    }


    isPalinNum(int i){

    }

};

int main()
{

}
