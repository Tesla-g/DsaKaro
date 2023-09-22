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
    
    int sizell(ListNode * head ){
      int cnt =0;
        if(!head) return 0;
        
      ListNode * t= head;
        while( t!=NULL){
            
            t=t->next;
            cnt++;
            
        }
        return cnt ;
      
      
      
   }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n<=0) return head;
        ListNode * t= head;
        auto e=  sizell(head);
        if(n>e) return head;
        if( e==n){
            head=t->next;
            delete t;
            return head ;
            
            
            
        }
       int pos=abs(e-n)-1 ;
       
        
        
        for(int i =0;i<pos;i++){
            t=t->next;     
        }
       ListNode * temp = t->next;
        t->next = t->next->next;
       temp->next=nullptr;
        return head;
        
        
        
        
    }
};