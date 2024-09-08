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
// Iterate method;
// just switch infors inside the pointers
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *record = head;
        if (head == NULL || head->next== NULL) return head; //if one or void node list, do nothing;
        ListNode *curr = head->next;        //starts from second;
        ListNode *pre = head;
        ListNode *leadsTo=head;
        head->next = NULL;
        while(curr!=NULL)
        {
            leadsTo=curr->next;     //remember where to go
            curr->next=pre;         //point current node->next = previous node;
            pre=curr;               //change reverse target to next;
            curr=leadsTo;
        }
        return pre;         //since curr == NULL, we saved pre is new start of list
        
    }
};
