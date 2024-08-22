class Solution {
public:
    int m, n; 
    int helper(int i, int j, string &str1, string &str2,vector<vector<int>>&dp){
        if(i<0 or j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0; int ans2=0;
        if(str1[i]==str2[j]){
            ans+=1+helper(i-1,j-1, str1, str2,dp);
        }else{
          ans2+=max(helper(i,j-1,str1,str2,dp),helper(i-1,j, str1, str2,dp));   
        }
        
        return dp[i][j]=max(ans, ans2);
        // if the elemen is not euql then do what 
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size();
        n=text2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        return helper(m-1, n-1, text1, text2,dp);
    }
};