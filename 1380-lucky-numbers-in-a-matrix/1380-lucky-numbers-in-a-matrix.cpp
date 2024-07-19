class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowMins(m, INT_MAX); 
        vector<int> colMaxs(n, INT_MIN); 
        vector<int> ans;

        // Find the minimum element in each row
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
               rowMins[i]=min(rowMins[i], matrix[i][j]);
            }
        }

        // Find the maximum element in each column
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                colMaxs[j]=max(colMaxs[j], matrix[i][j]);
            }
        }

        // Find all elements that are both row minimums and column maximums
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};

