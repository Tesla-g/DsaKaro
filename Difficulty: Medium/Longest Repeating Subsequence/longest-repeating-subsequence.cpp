//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int m ,n; 
        int helper(int i, int j, string &s1, string &s2,vector<vector<int>>&dp){
            if(i>=m or j>=n){
                return 0;
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            int res=0 ; int res2=0;
            if(s1[i]==s2[j] and i!=j){
                res+=1+helper(i+1, j+1, s1,s2,dp);
            }else{
                res2+=max(helper(i+1, j,s1, s2,dp), helper(i,j+1, s1, s2,dp));
            }
            
            return dp[i][j]=max(res, res2);
        }
		int LongestRepeatingSubsequence(string str){
		    // Code here
    		    n=m=str.size();
    		    vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
		     return  helper(0,0, str,str,dp);
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends