//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int bfs(vector<vector<int>>& grid) {
        typedef pair<int, pair<int, int>> P; // Pair to store (cost, (x, y))
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Directions: up, down, left, right

        auto isvalid = [&](int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n;
        };

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;

        while (!pq.empty()) {
            auto top = pq.top();
            int currSum = top.first;
            int x = top.second.first;
            int y = top.second.second;
            pq.pop();

            // If we reached the bottom-right cell
            if (x == m - 1 && y == n - 1) {
                return currSum;
            }

            // Explore neighbors
            for (auto& ele : dir) {
                int currx = x + ele[0];
                int curry = y + ele[1];

                // Check if the neighbor is valid and not visited
                if (isvalid(currx, curry) && !vis[currx][curry]) {
                    pq.push({currSum + grid[currx][curry], {currx, curry}});
                    vis[currx][curry] = true;
                }
            }
        }
        // If somehow no path is found, though not expected in a valid grid
        return -1;
    }
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        return bfs(grid);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends