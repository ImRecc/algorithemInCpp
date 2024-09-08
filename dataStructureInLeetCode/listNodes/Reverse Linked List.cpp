//https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1205/
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
        ListNode* prev = nullptr;  // Previous node, initially null
        ListNode* current = head;  // Current node, starting with head
        ListNode* next = nullptr;  // Temporary storage for next node
        
        while (current != nullptr) {
            next = current->next;   // Store the next node
            current->next = prev;   // Reverse the link
            prev = current;         // Move prev forward
            current = next;         // Move current forward
        }
        
        return prev;  // prev will be the new head of the reversed list
    }
};
