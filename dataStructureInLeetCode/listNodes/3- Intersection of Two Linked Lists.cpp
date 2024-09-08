//https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1215/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//considering the length,both:
//head->meeting point->end
//so long they are intersected, only difference are locked on head->meeting point
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int length1=0, length2=0;
        ListNode *p1=headA;
        ListNode *p2=headB;
        while(p1!=NULL)
        {
            p1=p1->next;
            length1++;
        }
        while(p2!=NULL)
        {
            p2=p2->next;
            length2++;
        }
        
        p1=headA;
        p2=headB;
        while(length1!=length2)
        {
            if(length1>length2)
            {
                p1=p1->next;
                length1--;
            }
            else
            {
                p2=p2->next;
                length2--;
            }
        }
        
        //aligned, now traverse
        //incase they are same at first and avoid unnecessary traverse.
        while(p1!=NULL) //they aligned, so one for all
        {
            if(p1==p2)
            {
                return p1;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return nullptr;
    }
};
