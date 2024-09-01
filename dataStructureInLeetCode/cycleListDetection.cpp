class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = p1->next;
        if(p2==null) return; //incase just one node
        while (p1 != null)  //when p1 traveled to void, means there are a boundaries exsist.
        {
            if (p1!=p2) 
            {
                p1=p1->next;  
                p2=p2->next->next;  //let's say there are a cycle, p1 are slower than p2, so the must be a time p2 chased p1 (p1==p2)
            }
            else return true;  //p1!=null and p1==p2, yes, there are cycle
        }
      return false;
    }
};
