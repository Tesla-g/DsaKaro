#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{0,-1},{-1,0},{1,0},{0,1}};
    
    bool search(int idx, int i, int j, string& word, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if(idx == word.size()) return true;
        
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) return false;
        
        if(board[i][j] != word[idx]) return false;
        
        visited[i][j] = true;
        
        for(int d = 0; d < directions.size(); d++) {
            int new_i = i + directions[d][0];
            int new_j = j + directions[d][1];
            
            if(search(idx + 1, new_i, new_j, word, board, visited)) return true;
        }   
        
        visited[i][j] = false;
        return false;
    }
        
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && search(0, i, j, word, board, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
