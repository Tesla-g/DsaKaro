//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
#define ll long long int
    
    ll solve(ll i, int coins[], int n, int sum, int currsum, vector<vector<ll>>& dp) {
        if (currsum > sum) return 0;
        if (currsum == sum) return 1;
        if (i >= n) return 0;

        if (dp[i][currsum] != -1) return dp[i][currsum];

        // Option 1: Include the current coin
        ll op1 = solve(i, coins, n, sum, currsum + coins[i], dp);
        
        // Option 2: Exclude the current coin and move to the next one
        ll op2 = solve(i + 1, coins, n, sum, currsum, dp);
        
        // Store the result in dp array and return
        return dp[i][currsum] = op1 + op2;
    }

    long long int count(int coins[], int N, int sum) {
        vector<vector<ll>> dp(N, vector<ll>(sum + 1, -1)); // DP table for memoization
        return solve(0, coins, N, sum, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends