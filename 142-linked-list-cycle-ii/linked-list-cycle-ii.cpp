/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode  *temp=head;
      unordered_map< ListNode  *,int> mp;
         ListNode  *val;
        int idx=0;
        while(temp){
        if(mp.find(temp)!=mp.end())
         {
          return temp;
          }
            mp[temp]=idx;
               idx++;
        
        temp=temp->next;
        }
        return nullptr;
        
    }
};