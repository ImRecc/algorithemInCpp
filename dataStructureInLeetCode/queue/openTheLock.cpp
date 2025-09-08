class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1; // 初始状态被锁
        
        queue<string> toVisit; // 队列存状态
        toVisit.push("0000");
        visited.insert("0000");
        int steps = 0;
        
        while (!toVisit.empty()) {
            int layerSize = toVisit.size(); // 当前层状态数
            for (int i = 0; i < layerSize; ++i) 
            {
                string currState = toVisit.front();
                toVisit.pop();
                if (currState == target) return steps;
                
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
                    }
                    // -1
                    nextState = currState;
                    nextState[pos] = (currDigit - '0' - 1 + 10) % 10 + '0';
                    if (!visited.count(nextState)) 
                    {
                        toVisit.push(nextState);
                        visited.insert(nextState);
                    }
                }
            }
            steps++; // 层结束，步数加 1
        }
        return -1; // 无解
    }
};
