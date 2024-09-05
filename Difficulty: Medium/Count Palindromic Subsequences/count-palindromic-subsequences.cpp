//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
  long long int const MOD = 1000000007;
    int solve(int i,int j,string &s,vector<vector<long long int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==j) return dp[i][j]=1;
        
        if(s[i]==s[j])
          return dp[i][j]=(1+solve(i+1,j,s,dp)+solve(i,j-1,s,dp))%MOD;
        else
          return dp[i][j]=(solve(i+1,j,s,dp)+solve(i,j-1,s,dp)-solve(i+1,j-1,s,dp)+MOD)%MOD;
    }
    
    
    long long int  countPS(string s)
    {
       int n=s.length();
       vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
       return solve(0,n-1,s,dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends