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
    int levelorder(TreeNode * root){
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode * > q; 
        q.push(root);
        int depth=1;
        while(!q.empty()){
          
            int size= q.size();
            // process the current level
            while(size--){
                auto r= q.front();
                q.pop();
                if(r->left==nullptr and r->right==nullptr){
                    // nearest leaf node
                    return depth;
                }
                if(r->left!=nullptr){
                    q.push(r->left);
                }
                if(r->right!=nullptr){
                    q.push(r->right);
                }
                
            }
            //after processing the level 
            // if you does not find any leaf node
            depth+=1;
  
        }
        // if you does not return anything that mean there is cycle
        return -1;
    }
    int minDepth(TreeNode* root) {
        return levelorder(root);
    }
};