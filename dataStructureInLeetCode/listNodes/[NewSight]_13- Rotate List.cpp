//https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1295/
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

//we don't needs to move any nodes, we just find the new head's position
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;
        
        ListNode *oldTail = head; //this gonna be tail of origin node when length are calculated
        int length=1;
        while(oldTail->next!=nullptr)
        {
            oldTail=oldTail->next;
            length+=1;
        }
        
        //circular the list
        oldTail->next = head;
        
        // Step 3: Calculate the new head position
        k = k % length;  // Handle cases where k >= length
        if (k == 0) 
        {
            oldTail->next = nullptr;  // Break the circular link if no rotation needed
            return head;
        }
        //so think of a cycled linked list, the ranges of nodes should be moved
        //decided the new head node's position
        //which is k far away the head's node
        ListNode *newTail = head;
        for (int i = 0; i < length - k - 1; ++i) 
        {
            newTail = newTail->next;
        }
         // Set new head
        ListNode *newHead = newTail->next;

        // Break the circular link
        newTail->next = nullptr;

        return newHead;
        
    }
};
