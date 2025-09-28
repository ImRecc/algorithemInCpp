/*这不就什么括号配对或者后序四则运算那种么,遇到]前就入栈,遇到第一个]就出栈直到遇到第一个[与[前面的数字来决定复读几次这样子
*/
//当然,建议双栈
class Solution {
public:
    string decodeString(string s) {
        stack<int> numStk; // 存重复次数
        stack<string> strStk; // 存字符串
        string currStr = ""; // 当前字符串
        int currNum = 0; // 当前数字
        
        for (char c : s) 
        {
            if (isdigit(c)) 
            { // 数字（多位）
                currNum = currNum * 10 + (c - '0');
                //将字符串中的多位数字（如 "123"）逐步构建成整数（如 123）
                //c-'0'=int, int+'0'=char;
            } else if (c == '[') { // 入栈
                numStk.push(currNum);//这个[所属的次数也要入了,就是当前的currNum
                strStk.push(currStr);
                currNum = 0;
                currStr = "";
            } else if (c == ']') 
            { // 处理括号
                int repeat = numStk.top(); numStk.pop();
                string prevStr = strStk.top(); strStk.pop();
                string temp = "";
                for (int i = 0; i < repeat; ++i) 
                {
                    temp += currStr;
                }
                currStr = prevStr + temp;
            } else 
            { // 字母
                currStr += c;
            }
        }
        return currStr;
    }
};
