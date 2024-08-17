class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        // DP table to store max scores
        vector<long long> prev_dp(n, 0);
        vector<long long> curr_dp(n, 0);

        // Initialize the first row
        for (int j = 0; j < n; ++j) {
            prev_dp[j] = points[0][j];
        }

        // Iterate through each row
        for (int i = 1; i < m; ++i) {
            // Calculate left and right maximums
            vector<long long> left_max(n, 0);
            vector<long long> right_max(n, 0);

            left_max[0] = prev_dp[0];
            for (int j = 1; j < n; ++j) {
                left_max[j] = max(left_max[j - 1], prev_dp[j] + j);
            }

            right_max[n - 1] = prev_dp[n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; --j) {
                right_max[j] = max(right_max[j + 1], prev_dp[j] - j);
            }

            // Fill the current DP row
            for (int j = 0; j < n; ++j) {
                curr_dp[j] = points[i][j] + max(left_max[j] - j, right_max[j] + j);
            }

            // Move current row to previous for the next iteration
            prev_dp = curr_dp;
        }

        // The result is the maximum in the last DP row
        return *max_element(prev_dp.begin(), prev_dp.end());
    }
};

