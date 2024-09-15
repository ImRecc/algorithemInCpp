//https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1228/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int val) : val(val), next(nullptr) {}
 *     ListNode(int val, ListNode *next) : val(val), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //sum / 10; get first slot digits
        //sum % 10; get second one digital
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int temp=0, carry=0;
        while(l1!=nullptr || l2!=nullptr || carry!=0)
        {
            temp=carry;
            if(l1!=nullptr)
            {
                temp+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr)
            {
                temp+=l2->val;
                l2=l2->next;
            }
            carry = temp / 10;
            current->next = new ListNode(temp % 10);
            current = current->next;
            
        }
        return dummyHead->next;
    }
};
