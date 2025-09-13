/*遇到左边的各种括号就入栈，是右边的就出栈，找对不对的上，([)]这种是不算合法的，那就非常简单了，再复杂的括号配对序列进来，第一个右括号面对的只能是一个同种的左括号
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; // 存左括号
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') { // 左括号入栈
                stk.push(c);
            } else { // 右括号
                if (stk.empty()) return false; // 无左括号匹配
                char top = stk.top();
                stk.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false; // 不匹配
                }
            }
        }
        return stk.empty(); // 确保无多余左括号
    }
};
