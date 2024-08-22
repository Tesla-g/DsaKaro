//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    
    int longestPalinSubseq(string A) {
        //code here
        string s1= A;
        reverse(A.begin(),A.end());
        string s2=A;
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n;j++){
                int res1=0; int res2=0;
                if(s1[i-1]==s2[j-1]){
                    res1+=1+dp[i-1][j-1];
                }else{
                    res2=max(dp[i][j-1], dp[i-1][j]);
                }
                dp[i][j]=max(res1,res2);
            }
        }
        return dp[m][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends