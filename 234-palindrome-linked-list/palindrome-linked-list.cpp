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
        if(!head) return false;
        string s="";
        ListNode * t=head;
       while(t!=nullptr){
            s+=to_string(t->val);
           t=t->next;
       }
        string temp=s;
        reverse(temp.begin(),temp.end());
        if(temp==s){
            return true;
        }
        return false;
      
    }
};