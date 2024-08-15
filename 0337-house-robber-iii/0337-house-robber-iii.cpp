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
    unordered_map<TreeNode*, int>memo;
    int helper(TreeNode* root){
        
        if(root==nullptr){
            return 0;
        }
        if(memo.count(root)){
            return memo[root];
        }
        int ans_robbed=root->val;
        if(root->left!=nullptr){
            // add the 
            ans_robbed+=helper(root->left->left)+helper(root->left->right);
        }
        if(root->right!=nullptr){
            ans_robbed+=helper(root->right->left)+helper(root->right->right);
        }
        // skip the case when the data is 
        
        int ans_not_robbed=helper(root->left)+helper(root->right);
        memo[root]= max(ans_robbed, ans_not_robbed);
        return memo[root];
    }
    int rob(TreeNode* root) {
        
        return helper(root);
        
        
        
        
    }
};