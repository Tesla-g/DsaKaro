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
    TreeNode* deleteHelper(TreeNode* root ,auto st, vector<TreeNode*>&result){
        if(root==NULL)
            return NULL;
        
        root->left=deleteHelper(root->left,st, result);
        root->right=deleteHelper(root->right,st,result);
        
        if(st.find(root->val)!=st.end()){
            if(root->left != nullptr){
               result.push_back(root->left); 
            }
            if(root->right!=nullptr){
                result.push_back(root->right);
            }
            return NULL;
        }else{
            // if the root does not exist and 
            return root;
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st; vector<TreeNode* > result;
        for(auto &ele: to_delete){
            st.insert(ele);
        }
        deleteHelper(root,st,result);
        // check for the first node and understand and 
        if(st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
    }
};