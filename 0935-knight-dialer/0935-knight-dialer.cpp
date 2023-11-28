class Solution {
public:
    int mod = 1000000007;

    long long int p(int i, int j, int jump, vector<vector<int>> &grid, vector<vector<vector<long long int>>> &memo) {
        if (i >= 4 || j >= 3 || i < 0 || j < 0 || grid[i][j] == 1) {
            return 0;
        }
        if (jump == 0) {
            return 1;
        }
        if (memo[i][j][jump] != -1) {
            return memo[i][j][jump];
        }

        long long int r1 = p(i - 2, j - 1, jump - 1, grid, memo);
        long long int r2 = p(i - 2, j + 1, jump - 1, grid, memo);
        long long int r3 = p(i - 1, j - 2, jump - 1, grid, memo);
        long long int r4 = p(i - 1, j + 2, jump - 1, grid, memo);
        long long int r5 = p(i + 1, j - 2, jump - 1, grid, memo);
        long long int r6 = p(i + 1, j + 2, jump - 1, grid, memo);
        long long int r7 = p(i + 2, j - 1, jump - 1, grid, memo);
        long long int r8 = p(i + 2, j + 1, jump - 1, grid, memo);
        return memo[i][j][jump] = (r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8) % mod;
    }

    int knightDialer(int n) {
        vector<vector<int>> grid(4, vector<int>(3, 0));
        grid[3][0] = 1;
        grid[3][2] = 1;

        vector<vector<vector<long long int>>> memo(4, vector<vector<long long int>>(3, vector<long long int>(n + 1, -1)));

        long long int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                
                if((i==3 && j==0 )|| i==3&& j==2){
                    continue;
                }
                ans = (ans + p(i, j, n - 1, grid, memo)) % mod;
            }
        }

        if (n == 1) return 10;
        return ans % mod;
    }
};