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
/*每两个相邻互换，比如 1→2→3，只换 1 和 2，3 不用理”
“用递归，从 head 开始，temp = head, head = head->next, head->next = temp，再递归处理 head->next->next”
“递归出口：head == null || head->next == null”
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 出口：0 或 1 个节点
        if (!head || !head->next) return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        
        // 递归交换后面的
        first->next = swapPairs(second->next);
        // 交换当前两个
        second->next = first;
        
        return second;  // 新头是 second
    }
};
