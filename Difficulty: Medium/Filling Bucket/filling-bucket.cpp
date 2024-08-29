//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

     int ways(int i,vector<int> &dp)
    {
        if(i==0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int t1=ways(i-1,dp);
        int t2=ways(i-2,dp);
        return dp[i]=(t1%100000000+t2%100000000)%100000000;
    }
    int fillingBucket(int N) {
        
        vector<int> dp(N+1,-1);
        return ways(N,dp)%100000000;
        // code here
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends