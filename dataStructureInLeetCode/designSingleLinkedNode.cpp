/*class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} //Member Initializer List
    //equals to:
       ListNode(int x) {
        val = x;
        next = NULL;
        }
    };
*/
//Use the ListNode already defined by LeetCode

class MyLinkedList {

private:
    ListNode* head;  // Pointer to the first node in the list
    int size;        // Number of elements in the list
    
    
public:
    
    MyLinkedList() {
        head = nullptr;  // Initialize an empty list
        size = 0;        // Start with size 0        
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1; //invalid
        
        ListNode *current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->val;  // Return the value at the given index
    }
    
    void addAtHead(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        
        if (size == 0) 
        {
            head=newNode;
        }
        
        else 
        {
            ListNode* current = head;
            while (current->next != nullptr) 
            {
                current = current->next;
            }
            current->next = newNode;
        
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) 
        {
            addAtHead(val);
        } 
        else 
        {
            ListNode *newNode = new ListNode(val);
            ListNode *current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            ListNode *toDelete = head;
            head = head->next;
            delete toDelete;
        } 
        else {
            ListNode *current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            ListNode *toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
        size--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
