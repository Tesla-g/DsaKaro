class Solution {
public:
    bool checkPowerofFive(string &s) {
        long long num = 0;
        for (char c : s) {
            num = num * 2 + (c - '0');
        }
        if (num == 0) return false;
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }

    int solve(int ind, string &s, int n, vector<int>& memo) {
        if (ind == n) {
            return 0;
        }
        if (memo[ind] != -1) {
            return memo[ind];
        }
        int ans = INT_MAX;
        string dummy = "";
        for (int i = ind; i < n; i++) {
            dummy += s[i];
            if (dummy[0] != '0' && checkPowerofFive(dummy)) {
                int res = solve(i + 1, s, n, memo);
                if (res != INT_MAX) {
                    ans = min(ans, 1 + res);
                }
            }
        }
        return memo[ind] = ans;
    }

    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        int result = solve(0, s, n, memo);
        return result == INT_MAX ? -1 : result;
    }
};