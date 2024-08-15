class Solution {
public:
    int solve(int i, vector<int>nums,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int op1=nums[i]+solve(i+2, nums,dp);
        // if the ith house is robbed then god for the 
        int op2=solve(i+1, nums,dp);
        dp[i]= max(op1, op2);
         return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2, -1);
        return solve(0, nums,dp);
        // This can be solved and what will be the nature of 
    }
};