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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        if(list1==nullptr or list2==nullptr)return nullptr;
        ListNode* ltemp=list1;
        for(int i=0;i<a-1;i++){
            ltemp=ltemp->next;
        }
        ListNode* ltemp2=list1;
       for(int i=0;i<=b;i++){
            ltemp2=ltemp2->next;
        }
        
        ListNode* t=list2;
        while(t->next!=nullptr){
            t=t->next;
        }
        t->next=ltemp2;
        ltemp->next=list2;
        
        return list1;
    }
};