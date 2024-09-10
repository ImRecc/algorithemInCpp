//https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1227/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //edge case test, see if one nodes or no nodes
        // Use two pointers to compare nodes from both lists
        ListNode* basePtr = list1;
        ListNode* targetPtr = list2;
        
        ListNode dummy(0);
        ListNode* current = &dummy;
        //this is what happens when no space complexity require.. we made new list and it helps a lot
        
        while(basePtr!=nullptr&&targetPtr!=nullptr) //we can't hanld all void case
        {
            if (basePtr->val <= targetPtr->val) 
            {
                current->next = basePtr;
                basePtr = basePtr->next;
            } else 
            {
                current->next = targetPtr;
                targetPtr = targetPtr->next;
            }
            current = current->next;
        }
         // Attach the remaining nodes from either listA or listB
        if (basePtr != nullptr) 
        {
            current->next = basePtr;
        } 
        else 
        {
            current->next = targetPtr;
        }
        
        // Return the merged list, which starts from the node after the dummy node
        return dummy.next;
        
    }
};
