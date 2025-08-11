//kmp算法，对needle进行预处理，懒得多说
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // 空 needle 返回 0
        int n = haystack.size(), m = needle.size();
        if (m > n) return -1; // needle 太长
        
        // 步骤 1：构建 LPS 表
        vector<int> lps(m, 0); // LPS 数组，类似能量模式表
        int len = 0, j = 1; // len 是当前最长前缀后缀长度
        while (j < m) {
            if (needle[j] == needle[len]) {
                lps[j++] = ++len; // 前缀后缀匹配，len 增加
            } else if (len > 0) {
                len = lps[len - 1]; // 回退到上一个匹配
            } else {
                lps[j++] = 0; // 无匹配，lps[j] = 0
            }
        }
        
        // 步骤 2：KMP 匹配
        int i = 0, k = 0; // i 指向 haystack，k 指向 needle
        while (i < n) {
            if (haystack[i] == needle[k]) {
                i++; k++; // 匹配，继续前进
                if (k == m) return i - m; // 找到完整匹配
            } else if (k > 0) {
                k = lps[k - 1]; // 不匹配，跳到 lps[k-1]
            } else {
                i++; // k=0，haystack 前进
            }
        }
        return -1; // 无匹配
    }
};
