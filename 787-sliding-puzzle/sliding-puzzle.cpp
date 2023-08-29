class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        string gs = "123450"; // final state to match
        string s = ""; // initial state

        // Convert the 2D board to a string representation
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s += to_string(board[i][j]);
            }
        }

        set<string> visited; // create this to mark string as visited so that the same matrix can't come again
        queue<pair<string, int>> q; // create a queue with string matrix and the steps
        q.push({s, 0}); // initial steps is zero

        while (!q.empty()) {
            string t = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (t == gs) { // if the initial matrix is matched with the goal state
                return steps;
            }

            // Find the index of zero '0'
            int index = t.find('0');
            int x = index;

            // Define possible moves: up, down, left, right
            int dx[] = {0, 0, -1, 1};
            int dy[] = {-1, 1, 0, 0};

            if (x - 3 >= 0) { // up direction
                string temp = t;
                swap(temp[x], temp[x - 3]);
                if (visited.find(temp) == visited.end()) {
                    q.push({temp, steps + 1});
                    visited.insert(temp);
                }
            }
            if (x + 3 < 6) { // Down
                string temp = t;
                swap(temp[x], temp[x + 3]);
                if (visited.find(temp) == visited.end()) {
                    q.push({temp, steps + 1});
                    visited.insert(temp);
                }
            }

            if (x % 3 != 0) { // left direction is allowed
                string temp = t;
                swap(temp[x], temp[x - 1]);
                if (visited.find(temp) == visited.end()) {
                    q.push({temp, steps + 1});
                    visited.insert(temp);
                }
            }
            if (x % 3 != 2) { // right direction is allowed
                string temp = t;
                swap(temp[x], temp[x + 1]);
                if (visited.find(temp) == visited.end()) {
                    q.push({temp, steps + 1});
                    visited.insert(temp);
                }
            }
        }

        // If the matrix doesn't match the goal state, return -1
        return -1;
    }
};
