//https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1214/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) //interesting for ListNode *prt require... nullprt for it/
    {
        if (head == NULL || head->next == NULL)  //clever way to avoid NULL->next;
        {
            return nullptr; // The list is either empty or has only one node without a cycle
        }
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *p3 = head;
        while(p1!=NULL && p2!=NULL && p2->next != NULL) //no matter how over boundary, it's over.
        {
            p1=p1->next;
            p2=p2->next->next; //make them cycle or end;
            if(p1==p2)      //when cycle founded...
            {
                while(p1!=p3)
                {
                    p1=p1->next;
                    p3=p3->next;
                }
                return p3;      //see the draft for more details (
            }
            
        }
        return nullptr;
        //
    }
};
