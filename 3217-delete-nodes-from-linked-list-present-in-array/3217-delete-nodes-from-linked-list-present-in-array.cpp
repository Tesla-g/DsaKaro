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
    // Function to remove all nodes with values present in 'targets' set
    ListNode* removeLL(ListNode* head, unordered_set<int>& targets) {
        // Handle the case where head nodes have values in 'targets'
        while (head != nullptr && targets.count(head->val)) {
            ListNode* temp = head;
            head = head->next;
            delete temp;  // Delete the old head
        }

        // Now head is guaranteed to not have a target value (or be nullptr)
        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Traverse the list and remove nodes with values in 'targets'
        while (curr != nullptr) {
            if (targets.count(curr->val)) {
                prev->next = curr->next;
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;  // Delete the target node
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }

    // Function to modify the list by removing all values present in 'nums'
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (head == nullptr) return nullptr;  // Handle the empty list case

        // Convert nums into an unordered_set to speed up lookups (O(1) average)
        unordered_set<int> targets(nums.begin(), nums.end());

        // Remove all nodes whose values are present in the 'targets' set
        return removeLL(head, targets);
    }
};
