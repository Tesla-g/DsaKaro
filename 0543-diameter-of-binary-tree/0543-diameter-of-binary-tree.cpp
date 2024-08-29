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
        
        if(root==nullptr)return 0;
        auto left=height(root->left);
        auto right= height(root->right);
        return 1+max(left, right);
        
    }
    void solve(TreeNode * root, int &ans){
        if(root==nullptr){
            return ;
        }
       auto diameter=height(root->left)+height(root->right);
       ans=max(ans, diameter);
        solve(root->left,ans);
         solve(root->right,ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int ans=INT_MIN;
        solve(root,ans);
        return ans; 
    }
};