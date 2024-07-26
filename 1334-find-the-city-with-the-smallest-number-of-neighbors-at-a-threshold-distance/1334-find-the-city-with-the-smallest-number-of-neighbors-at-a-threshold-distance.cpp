#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dijkstra(const unordered_map<int, vector<pair<int, int>>>& adj, int n, int k, map<int, vector<int>>& ans, int startingNode) {
        vector<int> distances(n, INT_MAX);
        distances[startingNode] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, startingNode});
        
        while (!pq.empty()) {
            auto [currentDistance, node] = pq.top();
            pq.pop();
            
            if (currentDistance > distances[node]) continue;
            
            if (adj.find(node) != adj.end()) { // Check if node exists in the graph
                for (auto &[neighbor, weight] : adj.at(node)) {
                    int newDist = currentDistance + weight;
                    if (newDist < distances[neighbor]) {
                        distances[neighbor] = newDist;
                        pq.push({newDist, neighbor});
                    }
                }
            }
        }
        
        int reachableCount = 0;
        for (int i = 0; i < n; ++i) {
            if (i != startingNode && distances[i] <= k) {
                reachableCount++;
            }
        }
        ans[reachableCount].push_back(startingNode);
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto &v : edges) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        map<int, vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            dijkstra(adj, n, distanceThreshold, ans, i);
        }
        
        auto it = ans.begin();
        return *max_element(it->second.begin(), it->second.end());
    }
};
