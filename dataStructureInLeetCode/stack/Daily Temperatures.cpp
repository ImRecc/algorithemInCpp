//当然可以用队列之类的一个一个比咯，那样就是O(n^2)了
//用栈，记录的是索引，访问的是temperatures[stk.(top)];
//然后比对就是新元素比对栈里的值，只要有一个不符合条件就入栈（栈元素是单调不增的嘛）
//优势在于不会一直重复被比对所有待处理的元素（相比队列来说）
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> stk; // 存未匹配天索引
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int prev = stk.top();
                stk.pop();
                answer[prev] = i - prev; // 天数差
            }
            stk.push(i);
        }
        return answer;
    }
};
