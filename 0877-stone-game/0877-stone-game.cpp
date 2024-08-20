class Solution {
public:
    unordered_map<string, int> memo;

    int helper(int i, int j, char turn, vector<int>& piles) {
        if (i > j) {
            return 0;
        }

        string key = to_string(i) + "#" + to_string(j) + "#" + turn;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int result;
        if (turn == 'A') {
            result = max(piles[i] + helper(i + 1, j, 'B', piles),
                         piles[j] + helper(i, j - 1, 'B', piles));
        } else {
            result = min(helper(i + 1, j, 'A', piles),
                         helper(i, j - 1, 'A', piles));
        }

        memo[key] = result;
        return result;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        int aliceScore = helper(0, n - 1, 'A', piles);

        // Alice wins if she can get more than half the total sum
        return aliceScore > totalSum / 2;
    }
};
