/*可变与不可变mutable immutable:
void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

Mutable：直接修改 nums 数组。
Immutable 替代：创建新数组，复制旋转结果（空间 O(n)）。

*/
//双指针与滑动窗口都需要考虑空间分配，而直接反转整个字符串再反转每个词就容易多了
class Solution {
public:
    string reverseWords(string s) {
        // 步骤 1：清理多余空格
        int write = 0;
        for (int read = 0; read < s.length(); read++) { 
            if (s[read] != ' ') {
                s[write++] = s[read];
            } else if (write > 0 && s[write - 1] != ' ') {
                s[write++] = ' ';
            }
        }
        // 裁剪字符串（移除尾部多余字符）
        if (write > 0 && s[write - 1] == ' ') --write; // 移除尾部空格
        s.resize(write);                            //经历了for循环，字符串s应该最多就是write长度的有效句子+一个空格
        
        // 步骤 2：反转整个字符串
        reverse(s.begin(), s.end());
        
        // 步骤 3：反转每个单词
        int start = 0;
        for (int i = 0; i <= s.length(); i++) { 
            if (i == s.length() || s[i] == ' ') //来让i变成找到词尾的指针 
            {
                int end = i - 1;
                while (start < end) {
                    swap(s[start++], s[end--]); // 保持 start++ 和 end--
                }
                start = i + 1; //while结束应该是start == end, 那么应该同步一下i的位置 目前i作为指示词尾(空格)
            }
        }
        
        return s;
    }
};
/*write：写入位置，记录有效字符。
read：读取位置，遍历字符串。
条件：非空格：写入字符，write++。
空格且前字符非空格：写入单个空格，write++。

裁剪：s.resize(write) 移除多余字符
*/
