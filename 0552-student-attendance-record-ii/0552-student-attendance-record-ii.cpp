class Solution {
public:
    int memo[100001][2][3]; // Memoization table
     long long int MOD;
    long long int solve(int n, int i, int A, int L) {
        if (i == n) return 1;
        if (memo[i][A][L] != -1) return memo[i][A][L];

       long long  int count = 0;
        // Add 'P' and recurse
        count += solve(n, i + 1, A, 0);
        
        // Add 'A' if there's no 'A' already and recurse
        if (A < 1) {
            count += solve(n, i + 1, A + 1, 0);
        }

        // Add 'L' if there's no more than 2 consecutive 'L's
        if (L < 2) {
            count += solve(n, i + 1, A, L + 1);
        }

        return memo[i][A][L] = count%MOD;
    }

    int checkRecord(int n) {
        memset(memo, -1, sizeof(memo));
        MOD=1e9+7;
        return solve(n, 0, 0, 0);
    }
};
