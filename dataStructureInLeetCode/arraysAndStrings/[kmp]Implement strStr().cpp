//kmp算法，对needle进行预处理，懒得多说
/*普通方法：
就像在一本书里找一句话。你不会背，你只能一页一页、一个字一个字往下对照。累死。

KMP 的方法：
你记住了这句话里「自己和自己重复的部分」。
比如要找 "ABABAC"：

你知道它开头 "ABA" 跟中间 "ABA" 重复了。

所以如果你比对到 "ABA" 后发现下一个字不对，你不用回到开头一个字一个字重新比，而是直接跳到第二个 "ABA" 去继续。

👉 换成比喻：

普通匹配：就像你找钥匙开门，发现钥匙不对，就要跑回家重新翻找。

KMP：你提前在钥匙上刻了标记，知道「错了可以直接跳过哪些不用试的」，节省了来回跑的时间。

一句话总结：
KMP 就是利用「自己和自己重复的规律」，减少没必要的重复检查。
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // 空 needle 返回 0
        int n = haystack.size(), m = needle.size();
        if (m > n) return -1; // needle 太长
        
        // 步骤 1：构建 LPS 表
        vector<int> lps(m, 0); // LPS 数组，类似能量模式表
        //lps[m] = {0};：语法错误，{0} 不能直接赋值给单个元素，正确应为 lps[m] = 0;，且需确保 m 在 lps 范围内。
        //lps = [m, 0];：语法错误，[m, 0] 不是 C++ 合法写法。
        //vector<int> lps(m, 0);：正确，创建大小为 m 的向量，所有元素初始化为 0。
        //vector<int> lps = {m, 0};：正确，创建向量 {m, 0}，大小为 2。
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
