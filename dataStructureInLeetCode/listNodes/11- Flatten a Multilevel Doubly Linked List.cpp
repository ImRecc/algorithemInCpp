//https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1225/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        flattenHelper(head);
        return head;
    }
    
private:
    // Recursive helper function that returns the last node in the flattened list
    Node* flattenHelper(Node* node) 
    {
        Node* curr = node;
        Node* last = nullptr;
        
        while (curr) 
        {
            Node* nextNode = curr->next;  // Store next node in the list
            
            if (curr->child) 
            {
                // Recursively flatten the child list
                Node* childLast = flattenHelper(curr->child);
                
                // Connect current node to child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr; // Remove the child pointer
                
                // Connect the last node of the flattened child list to next node
                if (nextNode) 
                {
                    childLast->next = nextNode;
                    nextNode->prev = childLast;
                }
                
                last = childLast;  // Update the last node to childLast
            } 
            
            else 
            {
                last = curr;  // Update last node to current node
            }
            
            curr = nextNode;  // Move to next node
        }
        
        return last;  // Return the last node of the flattened list
    }
};
