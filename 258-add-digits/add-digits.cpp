class Solution {
public:
    int addDigits(int n) {
       
        while(n>=10){
          int sum=0;
        while(n>0){
           int a=n%10;
            sum+=a;
            n=n/10;
            
        }
            n=sum;
      
    }
        return n;
    }
};