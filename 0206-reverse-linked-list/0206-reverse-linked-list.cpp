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
    ListNode* reverseList(ListNode* head) {
        ListNode * temp=head;
        vector<int>v;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        ListNode*t=head;
        int n=v.size();
        for(int i=n-1;i>=0;i--){
                t->val=v[i];
            t=t->next;
        }
        return head;
        
    }
};