# FunTwist-P2.png
![funTwistP2](https://github.com/user-attachments/assets/1068683c-0884-49e8-8cdf-bde2c265e962)

# Understanding Dummy Node Techniques and Pointer vs Object Usage in Linked List Operations
in this puzzle, we needs remove Nth node, we might met some extremly case like 'only one node'  
to avoid list all the situation may encounter, we introduced 'dummy' nodes to make them common;  
`ListNode dummy(0, head)'
we made a dummy node by

to making a node,  
`ListNode *newList = new ListNode();` totally fine
newList are pointer to a ListNode **object**  
`new ListNode()` creates a new **_ListNode object_** on the heap and returns a pointer to it.
hence we can `newList->val` to address it;  
 `delete newList;` to release **_heap_** memos which need manually managements;  

 `ListNode dummy(0, head)` are equals to `ListNode dummy; dummy.val=0, dummy.next=head;`
 since leetcode defined a constructor initalizer;  
 this created a `listNode` object on **_stack_** and initializes `dummy` with it;  
 naturally, we access a **_member of object_** via '.' like `dummy.val`;
 this is happens on **_stack_** hence no needs to manually control memos;
