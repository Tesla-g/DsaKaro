class Solution {
public:
    int s(int nth,vector<int> &n,vector<int> &dp){
    if(nth==0){
        return n[0];
    }
    if(nth<0){
    	return 0;
    }
    if(nth==1){
    	return n[1];
    }
        if(dp[nth]!=-1){
            return dp[nth];
        }
  
        int n1=s(nth-1,n,dp)+n[nth];
        int n2=s(nth-2,n,dp)+n[nth];
        int n3=min(n1,n2);
        dp[nth]=n3;
     	return n3;
}
    int minCostClimbingStairs(vector<int>& cost) {
         
        vector<int> dp(cost.size()+1,-1);

           auto ans=min(s(cost.size()-1,cost,dp),s(cost.size()-2,cost,dp));
      return ans ;
    }
};