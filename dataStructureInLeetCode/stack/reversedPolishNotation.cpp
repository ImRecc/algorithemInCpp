/*比如输入3, 4, +, 5, *, 那就顺着先入3，再入4，遇到+，就连续弹两个然后4+3入7，然后入5，遇到*，那就得7*5=35；如果是3，4，5，*，-那也挺直观的，入3，4，5，遇到乘，那就是4*5=20，再遇到-，也就是3-20；总之就是一股脑的入，然后遇到运算符就弹两个，先进的在符号前面后进的在符号后面嘛
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk; // 存数字
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") { // 运算符
                int b = stk.top(); stk.pop(); // 栈顶，第二个操作数
                int a = stk.top(); stk.pop(); // 次栈顶，第一个操作数
                if (s == "+") stk.push(a + b);
                else if (s == "-") stk.push(a - b);
                else if (s == "*") stk.push(a * b);
                else stk.push(a / b); // 向零取整
            } else { // 数字
                stk.push(stoi(s));
            }
        }
        return stk.top(); // 最终结果
    }
};
