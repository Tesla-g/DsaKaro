/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       vector<int> v;
        
        ListNode * t=head;
        while(t!=NULL){
        v.push_back(t->val);
        t=t->next;
        }
        vector<int> v2;
        int n =v.size();
        int i=0;
        int j=v.size()-1;
        while(j>=0){
            v2.push_back(v[j]);
           j--;
        }
        
        
        for(int i =0;i<n;i++){
            
            if(v[i]!=v2[i]) return false;
        }
        
        return true; 
       
            
        
    }
};