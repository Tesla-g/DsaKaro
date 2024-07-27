class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> matrix(26, vector<long long>(26, INT_MAX));
        
        // Initialize the matrix with direct transformation costs
        for (int i = 0; i < original.size(); i++) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            matrix[s][t] = min(matrix[s][t], (long long)cost[i]);
        }

        // Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    // if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    // }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) continue;

            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (matrix[s][t] == INT_MAX) {
                return -1; 
            }

            ans += matrix[s][t];
        }
        return ans;
    }
};
