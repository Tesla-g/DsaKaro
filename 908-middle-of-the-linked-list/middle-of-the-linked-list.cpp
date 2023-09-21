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
    ListNode* middleNode(ListNode* head) {
         ListNode * t=head;
         int cnt=0;
        
         while(t!=NULL){
             
             cnt++;
             t=t->next;
             
         }
        if(!head || !head->next) return head;
        ListNode* s= head;
        ListNode* f=head->next;
        while(f!=NULL && f->next!=NULL){
             f=f->next->next;
            s=s->next;
            
           
        }
        if(cnt%2==0) return s->next;
        return s;
    }
};