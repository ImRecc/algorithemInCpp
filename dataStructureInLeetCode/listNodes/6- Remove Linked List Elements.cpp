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
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to simplify removal of head nodes
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Use two pointers: prev and current
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr) {
            if (current->val == val) {
                // Skip the current node by changing the next pointer
                prev->next = current->next;
            } else {
                // Move the prev pointer if no removal
                prev = current;
            }
            // Move the current pointer forward
            current = current->next;
        }
        
        // Return the new head of the list, which is dummy->next
        return dummy->next;
    }
};
