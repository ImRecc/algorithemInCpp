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
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        
        //int length=0; this are more plain however it's O(n) not o(n) 'o(2n) actually'
        //think about speed&distance theory in cycleList puzzle
        //fast ptr are 2x faster than slow ptr,
        //so when fast reached the end, slow one are right on the middle
        //when strictly limited on o(n) not O(n), identify the mid node are matter
        ListNode *slow = head; 
        ListNode *fast = head;
        //traverse to find even or odd
        //nullptr are more recommended in modern c++ coding
        while(fast!=nullptr && fast->next != nullptr) //when meet, it's safe to trave, no null->next happens
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        //fast move 2step a time, so when it comes to end, slow one are middle of journey
        //now the slow either in the mid, or n/2 position;
        
        //handle odd and even cases separately
        if ( fast != nullptr)
        {
            slow=slow->next;
        }
        
        //it has be reverse..
        ListNode *secondHalf = reverseList(slow);
        ListNode *firstHalf = head;
        while(secondHalf!=nullptr)
        {
            if(firstHalf->val!=secondHalf->val) return false;
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }
        return true;
    }

private:
        //reverse the secondHalf
        ListNode *reverseList(ListNode *head)
        {
            ListNode *prev = nullptr;
            ListNode *curr = head;
            while (curr) 
            {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        
       
        
};
