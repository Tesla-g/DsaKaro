class Solution {
public:
    
    int helper (int i, int j , int &m , int &n, vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==m-1 and j==n-1){
            return grid[i][j];
        }
        if(i>=m or j>=n){ // if the it value it above the the range 
            return INT_MAX;
         }
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]= min(helper(i,j+1, m,n,grid,dp), helper(i+1, j, m,n,grid,dp))+grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return  helper(0,0,m,n,grid,dp);
    }
};