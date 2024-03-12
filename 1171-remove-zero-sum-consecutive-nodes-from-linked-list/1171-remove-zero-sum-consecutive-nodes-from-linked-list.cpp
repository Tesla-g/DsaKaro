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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        unordered_map<int, ListNode*> mp;
        mp[0] = dummyNode;
        int prefSum = 0;

        while(head != nullptr){
            prefSum += head->val;
            if(mp.find(prefSum) != mp.end()){
                ListNode* start = mp[prefSum]; //start->next to head [delete all]
                int pf = prefSum;
                ListNode* temp = start;
                while(temp->next != head){
                    temp = temp->next;
                    pf += temp->val;
                    mp.erase(pf);
                }
                start->next = head->next;
            }else{
                mp[prefSum] = head;
            }
            head = head->next;
        }

        ListNode* newHead = dummyNode->next;
        delete(dummyNode);
        return newHead;
    }
};