//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    
    int solve(int i, int sum, vector<int>& coins, vector<vector<int>>& dp) {
        // Base cases
        if (sum == 0) return 0;  // No coins needed if the sum is 0
        if (i >= coins.size() || sum < 0) return INT_MAX;  // Not possible to form the sum

        // If the value has been computed before, return it
        if (dp[i][sum] != -1) return dp[i][sum];

        // Option 1: Include the current coin
        int include = INT_MAX;
        if (coins[i] <= sum) {
            int res = solve(i, sum - coins[i], coins, dp);
            if (res != INT_MAX) {
                include = 1 + res;  // Add 1 coin to the count
            }
        }

        // Option 2: Exclude the current coin
        int exclude = solve(i + 1, sum, coins, dp);

        // Store the result in dp array and return the minimum of the two options
        dp[i][sum] = min(include, exclude);
        return dp[i][sum];
    }

    int minCoins(vector<int> &coins, int sum) {
        vector<vector<int>> dp(coins.size(), vector<int>(sum + 1, -1));
        int result = solve(0, sum, coins, dp);
         return (result == INT_MAX) ? -1 : result;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends