class Solution {
public:
int s(int n,vector<int> &qb ){
if(n<0){
    return 0;
}
if(n==1 ||n==0){
   return 1;
}
if(qb[n]!=-1){
    return qb[n];
}
int s1=s(n-2,qb);
int s2=s(n-1,qb);
int sum=s1+s2;
   qb[n]= sum;
    return sum;


}
    int climbStairs(int n) {
        vector<int>qb(n+1,-1);
    return s(n,qb);
    }
};