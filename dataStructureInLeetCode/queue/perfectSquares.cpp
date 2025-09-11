/*贪心和正向着一个会漏一个会很复杂（难以处理4，4，4=12这种）
  所以可以还是贪心起步，但历遍每一种，比如n=12, 先看a=9  9,1,1,1 k=4
  然后试a=4, 4,4,4, k = 3
  然后a = 1, 1,1,1,1,1不用再试了，因为k已经大于最小的3
  */
/*思路上：给定一个n，它之下的平方根有a,b,c,d,e...然后我们就把每一个都放进来进行一次历遍查找，n-a的找一圈，找到底，比如12，12-9-1-1-1，然后再找12-4-4-4，12-1-1-1-1（这时候就可以停了，因为已知最小是4次）
但实际上，不会需要“已知最小次”这种，因为和12-4-4-4同批次处理的节点中，它就是最快的哪一个，看代码
*/
/*大循环while(!toVisit.empty())和小循环for (int i = 0; i < layerSize; ++i)这个算是很精妙的，队列只要不空就一直找，一个是当前有几个待处理的节点，当前都处理完了就必须要steps++，很有广度优先搜索的感觉：先把已知的处理了，然后把新的未知归队，下一次再处理，这样每一次就是每一步
*/
class Solution {
public:
    int numSquares(int n) {
        queue<int> toVisit; // 队列存剩余值
        unordered_set<int> visited; // 记录访问值，只需关心是否存在
        unordered_map<int, int> parent; // 记录路径（父节点），需要键值对
        toVisit.push(n);
        visited.insert(n);
        parent[n] = -1; // 起点无父节点
        int steps = 0; // 平方数数量
        
        while (!toVisit.empty()) 
        {
            int layerSize = toVisit.size(); // 当前层大小
            for (int i = 0; i < layerSize; ++i) 
            {
                int curr = toVisit.front(); // 当前剩余值
                toVisit.pop();
                if (curr == 0) 
                { // 找到解
                    // 可选：打印路径
                    vector<int> path;
                    int state = 0;
                    while (state != -1) 
                    {
                        path.push_back(state);
                        state = parent[state];
                    }
                    reverse(path.begin(), path.end());
                    // cout << "Path: ";
                    // for (int x : path) cout << x << " -> ";
                    // cout << endl;
                    return steps;
                }
                
                // 尝试减去每个平方数
                for (int j = 1; j * j <= curr; ++j) {
                    int next = curr - j * j; // 新剩余值
                    if (!visited.count(next)) {
                        toVisit.push(next);
                        visited.insert(next);
                        parent[next] = curr; // 记录父节点
                    }
                }
            }
            steps++; // 层结束，步数+1
        }
        return -1; // 理论上不会到达
    }
};
