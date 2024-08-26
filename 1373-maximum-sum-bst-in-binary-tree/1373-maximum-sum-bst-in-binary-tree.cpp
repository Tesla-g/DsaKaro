class Solution {
public:
    struct Result {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
        
        Result(bool isBST, int sum, int minVal, int maxVal)
            : isBST(isBST), sum(sum), minVal(minVal), maxVal(maxVal) {}
    };
    
    Result traverse(TreeNode* root, int &maxSum) {
        if (root == nullptr) {
            // Return a valid BST with sum 0 and min/max values that won't interfere with checks.
            return Result(true, 0, INT_MAX, INT_MIN);
        }
        
        // Recurse on the left and right subtrees
        auto left = traverse(root->left, maxSum);
        auto right = traverse(root->right, maxSum);
        
        // Check if the current subtree is a valid BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return Result(true, currSum, min(root->val, left.minVal), max(root->val, right.maxVal));
        } else {
            return Result(false, 0, 0, 0); // If not a BST, return false with sum 0
        }
    }
    
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        traverse(root, maxSum);
        return maxSum;
    }
};
