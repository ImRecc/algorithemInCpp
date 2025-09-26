/*
只能用栈，所以我觉得遇到元素想要存起来除了push别无他法，然后遇到peek或者是pop这俩需要“先进先出”的调用时，每遇到一次，就把当前栈的元素弹出然后顺序入第二个栈，这时，第二个栈的pop\peek操作就符合队列的预期了
*/
//push, o(1), pop\peek, 均摊O(1),可能会O(n), 因为可能需要倒转整个队列
class MyQueue {
private:
    stack<int> inStk; // 接收 push
    stack<int> outStk; // 提供 pop/peek
public:
    MyQueue() {}
    
    void push(int x) {
        inStk.push(x); // 直接入栈
    }
    
    int pop() {
        if (outStk.empty()) { // outStk 空，转移 inStk
            while (!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
        int val = outStk.top();
        outStk.pop();
        return val;
    }
    
    int peek() {
        if (outStk.empty()) { // outStk 空，转移 inStk
            while (!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
        return outStk.top();
    }
    
    bool empty() {
        return inStk.empty() && outStk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
