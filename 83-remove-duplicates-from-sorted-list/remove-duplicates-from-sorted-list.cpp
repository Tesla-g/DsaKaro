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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return NULL;
         ListNode * p =head;
        ListNode*c=head->next;
        
        while(c!=nullptr){
            if(p->val==c->val){
             p->next=c->next;
                delete c;
                c=p->next;
            }else{
                p=c;
                c=c->next;
                
            }
            
        }
        return head;
    }
};