class Solution {
public:
    int sumofDigits(int num){
        int sum=0;
        while(num>0){
            int ld=num%10;
            sum+=ld;
            num/=10;
        }
        return sum;
    }
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int num=sumofDigits(x);
        if(x%num==0) return num;
        return -1;
    }
};