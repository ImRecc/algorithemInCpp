//leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1296/
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
//we could just import a harshTable
//but for reason I don't know we move firstPointer N steps ahead and move both simultaneously are counted as one
//fair enough right? (my ass)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0, head); // for more details see description file 
        // https://github.com/ImRecc/algorithemInCpp/blob/main/dataStructureInLeetCode/listNodes/descriptions.md#understanding-dummy-node-techniques-and-pointer-vs-object-usage-in-linked-list-operations

        
        ListNode *p1 = &dummy; // Start p1 at the dummy node
        ListNode *p2 = &dummy; // Start p2 at the dummy node
        //why &? to access the address of object dummy;
        
        
        // Move p1 n+1 steps ahead so that p2 will be n steps behind p1
        for (int i = 0; i <= n; ++i) 
        {
            p1 = p1->next;
        }
        
        // Move p1 to the end, maintaining the gap
        while (p1 != NULL) 
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // Remove the nth node from the end
        p2->next = p2->next->next;
        //this is why we needs a dummy, p->next=NULL, than boom
        //with a dummy, even only one nodes, dummy->next->next are never exceeds edges;
        
        
        return dummy.next; // Return the head of the new list
        //still, watch the describe file for more details
    }
};
