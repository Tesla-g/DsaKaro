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
    bool isPalindrome(vector<int>&v){
        int n=v.size();
//         check if th e
       int i=0, j=n-1;
        while(i<=j){
            if(v[i]!=v[j]){
                return false;
            }
              i++;
              j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return false;
        vector<int>v;
        ListNode * t=head;
       while(t!=nullptr){
            v.push_back(t->val);
           t=t->next;
       }
        return isPalindrome(v);
    }
};