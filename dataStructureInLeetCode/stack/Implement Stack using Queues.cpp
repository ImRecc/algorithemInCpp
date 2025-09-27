/*push(x)：直接入队（队列尾）。
pop()/top()：出队直到倒数第二个元素，将每个出队元素重新入队（保持顺序）。
最后一个元素是栈顶（最新元素）。
pop()：不重新入队最后一个元素。
top()：重新入队最后一个元素。

empty()：检查队列是否为空。
*/
/*或是push时候旋转一下，这样push是o(n), pop和peek是o(1),*/

class MyStack {
private:
    queue<int> q; // 单队列
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x); // 入队
        int size = q.size();
        for (int i = 0; i < size - 1; ++i) { // 旋转，前 n-1 元素出队入队
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front(); // 队首是栈顶
        q.pop();
        return val;
    }
    
    int top() {
        return q.front(); // 队首是栈顶
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
