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
    ListNode * middleList(ListNode * head){
        if (!head) return head;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != nullptr and fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode * reverseList(ListNode * head){
        if (!head) return head;
        ListNode * prev = nullptr;
        ListNode * curr = head;
        while(curr != nullptr){
            ListNode * nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    ListNode * mergeList(ListNode* node1, ListNode *node2){
        ListNode * dummy = new ListNode(0);
        ListNode * tail = dummy;
        while(node1 != nullptr && node2 != nullptr){
            tail->next = node1;
            node1 = node1->next;
            tail = tail->next;
            tail->next = node2;
            node2 = node2->next;
            tail = tail->next;
        }
        if(node1 != nullptr)
            tail->next = node1;
        return dummy->next;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode * middle = middleList(head);
        ListNode * rev = reverseList(middle->next);
        middle->next = nullptr; // Set the next of middle to nullptr to split the list
        
        head = mergeList(head, rev);
    }
};
