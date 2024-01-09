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
  void leaf(TreeNode*root,vector<int>&values){
  if(root==NULL)return ;
  if(root->left==nullptr&& root->right==nullptr){
    values.push_back(root->val);
    return ;
  }
  leaf(root->left,values);
  leaf(root->right,values);
    return;

}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
          if(root1==NULL|| root2==NULL)return false;
  
     vector<int>ans;
     vector<int>ans2;
     leaf(root1,ans);
     leaf(root2,ans2);
      if(ans.size()!=ans2.size())return false;
       else{
        for(int i=0;i<ans.size();i++){
      if(ans[i]!=ans2[i]){
        return false;
      }

    }

  }
      return true;

    }
};