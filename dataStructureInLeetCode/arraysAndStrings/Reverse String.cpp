class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]); // 交换 s[i] 和 s[j]
            i++; // 头指针右移
            j--; // 尾指针左移
        }
    }
};
