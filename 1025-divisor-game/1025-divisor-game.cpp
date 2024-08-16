class Solution {
public:
    bool divisorGame(int n) {
        // Create a DP array where dp[i] means if Alice wins with i on the board
        vector<bool> dp(n + 1, false);
        
        // Base case
        dp[1] = false; // If n == 1, Alice loses
        
        // Fill the DP table
        for (int i = 2; i <= n; ++i) {
            for (int x = 1; x < i; ++x) {
                if (i % x == 0) {
                    // If Alice can force Bob into a losing position
                    if (!dp[i - x]) {
                        dp[i] = true;
                        break; // No need to check further, Alice can win
                    }
                }
            }
        }
        
        // Result for the original problem
        return dp[n];
    }
};
