class Solution {
public:
    int solve(int i,int n, vector<int>nums,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int op1=nums[i]+solve(i+2,n, nums,dp);
        // if the ith house is robbed then god for the 
        int op2=solve(i+1,n, nums,dp);
        dp[i]= max(op1, op2);
         return dp[i];
    }
    int rob(vector<int>& nums) {
       // if i rob the first house the last house will never be robbed
        // if the does not rob the first house hten 
        // then i rob the second house and th last house can be robbed easily 
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n+2, -1);
        vector<int>dp2(n+2,-1);
        // there iwll be n-1 elments in total  how man  1 n-1 
        auto ans1=solve(0,n-1, nums,dp1);
        auto ans2=solve(1, n, nums,dp2 );
        return max(ans1, ans2);
    }
};