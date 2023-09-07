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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* curr=head;
        int i=0;
        
      for(int i =0;i<left-1;i++)
      {
          pre=pre->next;
          
      }  
       curr= pre->next;
        ListNode* storelistaddress=curr;
        ListNode* prenode=NULL;
        for(int i =0;i<=right-left;i++){
            ListNode* temp=curr->next;
            curr->next=prenode;
            prenode=curr;
            curr=temp;
            
        }
      pre->next= prenode;
     storelistaddress->next=curr;
        return dummy->next;
        
        
        
  
    }
};