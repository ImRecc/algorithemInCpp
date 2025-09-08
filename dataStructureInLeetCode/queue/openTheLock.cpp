/*我来尝试总结一下这个解法：有点类似于numbers of island，只是这里的offset变成了+-1，因为一次只能挪一格，也只能正负方向挪；然后就一次性开始遍历所有数值；其中障碍被存进一个哈希表里，访问过但不是目标数的也塞入（insert)障碍哈希表里，然后利用队列先进先出的特性来记录经历过offset的当前数字？并且由于当前数字如果不是目标的话就可以在下一次循环里对队列头部元素进行一次+-1的查询。这时间复杂度简直太大了，layersize的数值第一次循环是1，第二次直接是8了吧，悲观估计确实不是很好，但是实际上被规则和已访问过滤了，也许折磨来折磨去找一些规则运算会好？但很复杂；
而且这个解法也没找出实际的路径的样子？我以前写过一个找括号配对的问题，我定了一大堆规则而没用栈来实现那种。
*/
//反正理论上能，实际上由于规则复杂、人脑历遍折磨导致输出路径思路像玄学
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1; // 初始状态被锁
        unordered_map<string, string> parent; // 记录路径
        
        
        queue<string> toVisit; // 队列存状态
        toVisit.push("0000");
        visited.insert("0000");
        parent["0000"] = "";
        int steps = 0;
        
        while (!toVisit.empty()) {
            int layerSize = toVisit.size(); // 当前层状态数
            for (int i = 0; i < layerSize; ++i) 
            {
                string currState = toVisit.front();
                toVisit.pop();
                if (currState == target) 
                {
                    // 可选：打印路径
                    vector<string> path;
                    string state = target;
                    while (state != "") 
                    {
                        path.push_back(state);
                        state = parent[state];
                    }
                    reverse(path.begin(), path.end());
                    // cout << "Path: ";
                    // for (string s : path) cout << s << " -> ";
                    return steps;
                }
                
                // 每位 ±1，生成 8 个新状态
                for (int pos = 0; pos < 4; ++pos) 
                {
                    char currDigit = currState[pos];
                    // +1
                    string nextState = currState;
                    nextState[pos] = (currDigit - '0' + 1) % 10 + '0';
                    //将字符 currDigit 转为整数。
                    //ASCII 编码中，'0' = 48，'1' = 49，... '9' = 57。
                    //'0' 是基准，currDigit - '0' 得到数字值：
                    //模 10 确保结果在 0-9 范围内
                    //-‘0’又在转位字符

                    if (!visited.count(nextState)) 
                    {
                        toVisit.push(nextState);
                        visited.insert(nextState);
                        parent[nextState] = currState;
                    }
                    // -1
                    nextState = currState;
                    nextState[pos] = (currDigit - '0' - 1 + 10) % 10 + '0';
                    if (!visited.count(nextState)) 
                    {
                        toVisit.push(nextState);
                        visited.insert(nextState);
                        parent[nextState] = currState;
                    }
                }
            }
            steps++; // 层结束，步数加 1
        }
        return -1; // 无解
    }
};
