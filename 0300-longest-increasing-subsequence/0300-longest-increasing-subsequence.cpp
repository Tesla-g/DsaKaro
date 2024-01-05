class Solution {
public:
int dp[2501][2501];
int n;
int solve(int i,vector<int>&v,int prev_max_index){
  if(i>=n){
    return 0;
  }
  
  if(prev_max_index!=-1&&dp[i][prev_max_index]!=-1)return dp[i][prev_max_index];
  int op1=0;
  if(prev_max_index==-1||v[i]>v[prev_max_index]){
    op1+=1+solve(i+1,v,i);
  }
  int op2=solve(i+1,v,prev_max_index);
  if(prev_max_index!=-1)   return dp[i][prev_max_index] =max(op1,op2);
  return max(op1,op2);

}


    int lengthOfLIS(vector<int>& nums) {
      
     n=nums.size();
   memset(dp,-1,sizeof dp);
      return solve(0,nums,-1);
      
    }
};