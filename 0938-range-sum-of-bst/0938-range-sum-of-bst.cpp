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
  set<int>s;
void rangeSum(TreeNode* root,int low,int high){
  if(root==nullptr)return ;
  if(root->val>=low && root->val<=high){
    s.insert(root->val);
  }
  if(root->val>low){
    rangeSum(root->left,low ,high);
  }
  if(root->val<high){
    rangeSum(root->right,low,high);
  }
  return ;
}
    int rangeSumBST(TreeNode* root, int low, int high) {
     rangeSum(root,low,high);
      int sum=0;
      for(auto & e: s){
        sum+=e;
      }
        return sum;
    }

};