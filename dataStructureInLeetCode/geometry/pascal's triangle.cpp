
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; // 结果数组
        
        // 空情况：numRows = 0
        if (numRows == 0) return result;
        
        // 第 0 行：[1]
        result.push_back({1});
        /* {1} 是初始化列表（Initializer List）：在 C++ 中，
        {1} 是一个std::initializer_list<int>，表示一个包含单一元素 1 的临时列表。
        对于 vector<int>，{1} 会被自动转换为一个 vector<int>，内容为 [1]。
        因此，result.push_back({1}) 是在 result
        （类型 vector<vector<int>>）末尾添加一个 vector<int>，即 [1]。 */
        if (numRows == 1) return result;
        
        // 从第 1 行到第 numRows-1 行
        for (int i = 1; i < numRows; i++) {
            vector<int> newRow(i + 1, 1); // 新行，长度 i+1，首尾为 1
            vector<int>& prev = result[i - 1]; // 上一行
            //vector<int>& prev 声明 prev 是一个 vector<int> 的引用，绑定到 result[i - 1]。
            //只有&variable这样的才是取地址符的用途
            //避免拷贝 vector<int>，提高效率（result[i - 1] 可能很大，拷贝耗时）
            
            // 计算中间元素
            for (int j = 1; j < i; j++) {
                newRow[j] = prev[j - 1] + prev[j]; // 上一行相邻元素之和
            }
            
            result.push_back(newRow); // 添加新行
        }
        
        return result;
    }
};
