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

        // Check memoized results
        if (dp[i][m][aliceturn] != -1) {
            return dp[i][m][aliceturn];
        }

        int points = 0;

        if (aliceturn) {
            int max_points = INT_MIN;
            int current_sum = 0;
            for (int j = 1; j <= min(2 * m, n - i); j++) {
                current_sum += piles[i + j - 1]; // Add stones from the next pile
                max_points = max(max_points, current_sum + helper(i + j, piles, n, max(m, j), false, dp));
            }
            dp[i][m][aliceturn] = max_points;
        } else {
            int min_points = INT_MAX;
            for (int j = 1; j <= min(2 * m, n - i); j++) {
                min_points = min(min_points, helper(i + j, piles, n, max(m, j), true, dp));
            }
            dp[i][m][aliceturn] = min_points;
        }

        return dp[i][m][aliceturn];
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // Adjust the dp array size for m to handle up to 2*n
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2 * n, vector<int>(2, -1)));
        return helper(0, piles, n, 1, true, dp);
    }
};
