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
    bool areIdentical(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
      
        // if any one of them is not nullptr and other is nullptr
        if (root == nullptr || subRoot == nullptr) {   // either both of them is not nullptr then do not do anything 
            return false;
        }
        auto left=  areIdentical(root->left, subRoot->left);
        auto right= areIdentical(root->right, subRoot->right);
        return (root->val==subRoot->val) and (left) and right; 
    }

    bool solve(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (areIdentical(root, subRoot)) {
            return true;
        }
        return solve(root->left, subRoot) || solve(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};