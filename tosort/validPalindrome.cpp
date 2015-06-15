/*	
Given a string, determine if it is a palindrome, 
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0) return true;
        char* p = &s[0];
        char* q = &s[s.length()-1];
        while(!(p==q) && !(p+1==q))
        {
            if (isAphaNum(*p) && isAphaNum(*q))
            {
                if (setCharCapt(*p) != setCharCapt(*q)) return false;
                else { p++; q--;}
            }
            else {
                if (!isAphaNum(*p)) p++;
                if (!isAphaNum(*q)) q--;}              
        }
        if (p+1==q) {
            if (isAphaNum(*p) && isAphaNum(*q)){
                if (setCharCapt(*p) != setCharCapt(*q)) return false;}
            else return true;}
        return true;  
    }
    
    bool isAphaNum(char c){
        if (((c <= 'z') && (c>='a'))
        || ((c <= '9') && (c>='0'))
        || ((c <= 'Z') && (c>='A'))) return true;
        else return false;        
    }
    
    char setCharCapt(char c){
        if ((c <= 'z') && (c>='a')) return c-32;   
    }
};
