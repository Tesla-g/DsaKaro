class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);  // Initialize DP table
        dp[0] = 0;  // Base case: 0 coins needed to make amount 0
        
        for (int i = 1; i <= amount; ++i) {
            for (auto &coin : coins) {
                if (coin <= i) { // if the coin is less than the amount 
                    // Update DP table entry for amount i
                    if (dp[i - coin] != INT_MAX) { // if the dp[i-coin ] is not INT_MAx;
                        dp[i] = min(dp[i], dp[i - coin] + 1);
                    }
                }
            }
        }
        
        // If dp[amount] is still INT_MAX, return -1 (not reachable)
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
