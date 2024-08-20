#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int helper(int i, vector<int>& piles, int n, int m, bool aliceturn, vector<vector<vector<int>>>& dp) {
        if (i >= n) {
            return 0; // No more piles to take
        }

        // If the result is already calculated
        if (dp[i][m][aliceturn] != -1) {
            return dp[i][m][aliceturn];
        }

        int result;
        int currstone = 0;

        if (aliceturn) {
            int max_points = INT_MIN;
            for (int j = 1; j <= 2 * m && i + j <= n; j++) {
                currstone += piles[i + j - 1]; // Accumulate points for Alice
                max_points = max(max_points, currstone + helper(i + j, piles, n, max(m, j), !aliceturn, dp));
            }
            result = max_points;
        } else {
            int min_points = INT_MAX;
            for (int j = 1; j <= 2 * m && i + j <= n; j++) {
                currstone += piles[i + j - 1]; // Accumulate points for Bob
                min_points = min(min_points, helper(i + j, piles, n, max(m, j), !aliceturn, dp));
            }
            result = min_points;
        }

        dp[i][m][aliceturn] = result;
        return result;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return helper(0, piles, n, 1, true, dp);
    }
};
