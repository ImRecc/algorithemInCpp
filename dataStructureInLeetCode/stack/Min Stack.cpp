//对于minStk, push倒是容易处理，pop就不容易了，所以不如再用一个栈，一边找最小，一边把“是当前最小”的元素们入栈
//由于是后进，所以更小的会后进，自然也会先出
/*即使是-2,0,-3这样的小-大-更小的入栈，哪怕全pop了，由于minStack是选择性弹出的，所以不会有minStack先弹空了的问题
*/
class MinStack {
private:
    stack<int> stk; // 存所有元素
    stack<int> minStk; // 存每次 push 时的最小值
public:
    MinStack() {
        // 无需显式初始化 MAX_INT，minStk 空
    }
    
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val <= minStk.top()) { // 新值 <= 当前最小
            minStk.push(val);
        }
    }
    
    void pop() {
        if (stk.top() == minStk.top()) { // 弹出元素是最小值
            minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top(); // 直接返回最小值
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
