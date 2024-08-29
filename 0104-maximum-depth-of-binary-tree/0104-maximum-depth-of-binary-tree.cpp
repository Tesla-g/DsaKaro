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
    int height(TreeNode * root){
        if(root==nullptr){
            return 0;
        }
        
        auto left= height(root->left);
        auto right= height(root->right);
        return 1+max(left,right);
        
        
    }
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};