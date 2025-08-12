//C++ 的 vector<string> 直接用 strs[j][i] 访问第 j 个字符串的第 i 个字符，无需单独变量
/*或者用const string& s = strs[j] 创建一个常量引用 s，绑定到 strs[j]（vector<string> 的第 j 个字符串）。
引用（&）：s 是 strs[j] 的别名，不复制字符串，节省内存和时间。
常量（const）：s 不可修改（例如不能 s[i] = 'x'），适合只读操作，如比较字符。
赋值：strs[j] 是 vector<string> 的元素（类型 string），s 直接引用它。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // 空数组返回 ""
        if (strs.size() == 1) return strs[0]; // 单字符串返回本身
        
        string result; // 结果字符串，类似公共能量模式
        // 以 strs[0] 为基准，逐位比较
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i]; // 基准字符
            // 检查 strs[1] 到 strs[n-1] 的第 i 个字符
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return result; // 越界或不匹配，返回当前结果
                }
            }
            result.push_back(c); // 匹配成功，添加字符
        }
        return result;
    }
};
