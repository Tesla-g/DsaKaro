/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& leafs, int& count, int distance) {
        queue<pair<TreeNode*, int>> que; // pair of node and current level
        unordered_set<TreeNode*> visited;
        que.push({root, 0});
        visited.insert(root);

        while (!que.empty()) {
            auto [node, level] = que.front();
            que.pop();

            if (node != root && leafs.find(node) != leafs.end() && level <= distance) {
                count++;
            }
            if (level < distance) {
                for (auto& neighbor : adj[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        que.push({neighbor, level + 1});
                    }
                }
            }
        }
    }

    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj) {
        if (root == NULL) {
            return;
        }
        if (prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        makeGraph(root->left, root, adj);
        makeGraph(root->right, root, adj);
    }

    void getAllLeafs(TreeNode* root, unordered_set<TreeNode*>& leafs) {
        if (root == NULL) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            leafs.insert(root);
        }
        getAllLeafs(root->left, leafs);
        getAllLeafs(root->right, leafs);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_set<TreeNode*> leafs;
        getAllLeafs(root, leafs);

        int count = 0;
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        makeGraph(root, NULL, adj);

        for (auto& leaf : leafs) {
            bfs(leaf, adj, leafs, count, distance);
        }

        // Since each pair is counted twice, divide the count by 2
        return count / 2;
    }
};