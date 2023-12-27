class Solution {
public:
    int mod = 1e9 + 7;
    int dp[31][1001][31];

    int s(int idx, int t, vector<int> &dice, int rolls) {
        if (t < 0) {
            return 0;
        }
        if (rolls == 0) {
            return (t == 0) ? 1 : 0;
        }
        if (idx >= dice.size()) {
            return 0;
        }
        if (dp[idx][t][rolls] != -1) return dp[idx][t][rolls];
        
        int ways = 0;
        for (int i = 1; i <= dice[idx]; i++) {
            ways = (ways + s(idx + 1, t - i, dice, rolls - 1)) % mod;
        }
        ways = (ways + s(idx + 1, t, dice, rolls)) % mod;
        
        return dp[idx][t][rolls] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<int> dice(n, k);  // Each dice can have values from 1 to k
        memset(dp, -1, sizeof(dp));
        return s(0, target, dice, n) % mod;
    }
};
