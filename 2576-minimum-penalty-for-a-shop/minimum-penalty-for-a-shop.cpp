class Solution {
public:
    int solve(string &str) {
        int n = str.size();
        vector<int> prefix_n(n + 1, 0);
        vector<int> suffix_y(n + 1, 0);

        // Calculate prefix_n array
        for (int i = 1; i <= n; i++) {
            prefix_n[i] = prefix_n[i - 1] + (str[i - 1] == 'N' ? 1 : 0);
        }

        // Calculate suffix_y array
        for (int i = n - 1; i >= 0; i--) {
            suffix_y[i] = suffix_y[i + 1] + (str[i] == 'Y' ? 1 : 0);
        }

        int minSum = INT_MAX;
        int minHour = -1;

        // Calculate the minimum sum of prefix_n and suffix_y
        for (int i = 0; i <= n; i++) {
            int currentSum = prefix_n[i] + suffix_y[i];
            if (currentSum < minSum) {
                minSum = currentSum;
                minHour = i;
            }
        }

        return minHour;
    }

    int bestClosingTime(string customers) {
        return solve(customers);
    }
};
