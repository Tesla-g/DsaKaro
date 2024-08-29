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
  int heightAndDiameter(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }

        // Recursively find the height of the left and right subtrees
        int leftHeight = heightAndDiameter(root->left, diameter);
        int rightHeight = heightAndDiameter(root->right, diameter);

        // Calculate the diameter passing through this node
        int currentDiameter = leftHeight + rightHeight;

        // Update the maximum diameter found so far
        diameter = max(diameter, currentDiameter);

        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int ans=INT_MIN;
        heightAndDiameter(root,ans);
        return ans; 
    }
};