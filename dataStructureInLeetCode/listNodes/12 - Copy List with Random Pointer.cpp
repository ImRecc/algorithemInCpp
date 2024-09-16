/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        vector<pair<Node*, Node*>> nodeList;
        //traversal the list and store the sequnce of nodes while establish the random pointer
        Node* curr=head;
        while(curr!=nullptr)
        {
            Node* newNode = new Node(curr->val); //worry not, this happens locally, 
                                                    //scoped to each iteration of the while loop. 
                                                    //variable name is reused in every iteration, 
                                                    //object that newNode points to is freshly .
            nodeList.push_back({curr, newNode});
            //dont hasty yet, we need translate the random pointers' infors
            curr=curr->next;
        }
        for(auto & p:nodeList)                      //&p make true operate instead of manuplating copy
        {
                                                    //manage the two pointers, according to vector stored
            Node* oldNode = p.first;
            Node* newNode = p.second;
            // Set next pointer
            if (oldNode->next!=nullptr) 
            {
                newNode->next = findCopy(nodeList, oldNode->next);
            }
            // Set random pointer
            if (oldNode->random) 
            {
                newNode->random = findCopy(nodeList, oldNode->random);
            }
        }
        return nodeList[0].second;
    }
    //no needs to explain whether for a senior or noob
private:
Node* findCopy(const vector<pair<Node*, Node*>>& nodeList, Node* node) {
    for (const auto& p : nodeList) 
    {
        if (p.first == node) {
            return p.second;
        }
    }
        return nullptr;
    }
};
