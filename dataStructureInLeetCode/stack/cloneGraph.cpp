/*
// Definition for a Node.
//这个Node是类的名字；
class Node {
public:
    int val;
    vector<Node*> neighbors; 
    //Node* 是指向 Node 类的指针，表示 Node 对象的地址。
    //每个 Node 对象代表图的一个节点，neighbors 存该节点的所有邻居节点（Node* 指针）。


    //我记得c语言有structure Node{};这种类似的，这个也差不多;
    Node() {
        val = 0;
        neighbors = vector<Node*>(); 
    }
    //Node 类的默认构造函数，创建 Node 类实例


    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    //和上文Node()不同，这个有传入值，上一个没有就默认为0；
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
    //同样，这个对neighbors向量有也有传入值
};
*/
//C++ 的 class 语法要求在一个块内定义：成员变量：如 int val;, vector<Node*> neighbors;（数据）。
//成员函数：如构造函数、其他方法（行为）。
//读起来是麻烦点


/*从起点节点开始，克隆节点（复制 val）。
标记节点为“已访问”（用哈希表）。
克隆邻居，标记邻居为已访问。
将邻居推入栈，依次处理邻居的邻居。
用哈希表避免重复访问（因图可能有环）。
需要：栈（管理待处理节点）+哈希表（记录已克隆节点）。
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloned; // 原 -> 新
        stack<Node*> stk; // 待处理原节点
        cloned[node] = new Node(node->val); // 克隆起点
        stk.push(node);
        
        while (!stk.empty()) 
        {
            Node* curr = stk.top(); stk.pop();
            for (Node* neighbor : curr->neighbors) 
            {
                if (!cloned.count(neighbor)) 
                { // 未克隆
                    cloned[neighbor] = new Node(neighbor->val);
                    stk.push(neighbor);
                }
                cloned[curr]->neighbors.push_back(cloned[neighbor]); // 连接
            }
        }
        return cloned[node];
    }
};
