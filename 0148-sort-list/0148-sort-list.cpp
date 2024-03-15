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
     ListNode* sortLinkedList (ListNode * head){
         if(!head || head->next==nullptr) return head;
  // this can be solved by solving the proper scenarion 
  vector<int>arr;
  ListNode *t =head;
  while(t!=nullptr){
    arr.push_back(t->val);
    t=t->next;
  }
  
  std::sort(arr.begin(),arr.end());
  ListNode * temp=head;
  for(auto ele : arr){
    temp->val=ele;
    temp=temp->next;
  }
      return head;   
         
     }
    ListNode* sortList(ListNode* head) {
        return sortLinkedList(head);
    }
};