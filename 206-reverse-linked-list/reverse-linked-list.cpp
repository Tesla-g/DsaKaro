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
        if(head==nullptr)return nullptr;
        ListNode * c = head ;
        ListNode * d = head->next;
        while( c!=nullptr &&d != nullptr){
            ListNode * t=d->next;
            d->next=c;
            c=d;
            d=t;
        }
        head->next=nullptr;
        return c;
    }
};