//https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1208/
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
    ListNode* oddEvenList(ListNode* head) {
        //we start with two nodes, odd and even, each one store different infor in 'next';
         if (head == NULL || head->next == NULL) return head; // Handle case where list has 0 or 1 node
        //at least, head->next can't be NULL
        ListNode dummyOdd(0, head);// （）
        ListNode dummyEven(0, head);
        ListNode* odd = &dummyOdd;
        ListNode* even = &dummyEven;
        ListNode* curr=head;
        int counter=1;
        
        while(curr!=NULL) //traverse till the end
        {
            if(counter%2==0) 
            {
                even->next=curr;
                even=even->next;
            }
            else 
            {
                odd->next = curr;
                odd=odd->next;
            }
            curr=curr->next;
            counter++;
        }
        even->next = NULL;
        //now both list are set
        odd->next=dummyEven.next;
        return dummyOdd.next;
    }
};
