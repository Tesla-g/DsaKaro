class Solution {
public:
   long long  int reverseNumber(int y){
      long long   int reverse=0;
        while(y>0){
           long long  int lastDigit=y%10;
            reverse=reverse*10+lastDigit;
            y/=10;
        }
        return reverse;
    }
    bool isPalindrome(int x) {
        if(x<0)return false;
    long long  int num=reverseNumber(x);
    return num==x;
    }
};