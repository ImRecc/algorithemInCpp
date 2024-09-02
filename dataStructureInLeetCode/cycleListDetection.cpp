/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *///
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)  //clever way to avoid NULL->next;
        {
            return false; // The list is either empty or has only one node without a cycle
        }
        ListNode *p1 = head;
        ListNode *p2 = head->next; //p1->next will leads to runtime error
        while (p1 != NULL && p2 != NULL && p2->next != NULL) 
        {
            if (p1 == p2) 
            {
                return true;  // Cycle detected
            }
            p1 = p1->next;
            p2 = p2->next->next;  //when we met loop, p2 are faster than p1, so they must met.
        }
      return false;
    }
};
