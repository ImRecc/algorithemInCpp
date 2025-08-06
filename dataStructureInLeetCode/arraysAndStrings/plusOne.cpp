// https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1148/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // 从右到左处理加法
        for (int i = n - 1; i >= 0; i--) {
            digits[i] += 1; // 加 1
            if (digits[i] < 10) {
                // 无进位，直接返回原数组
                return digits;
            }
            // 有进位，置当前位为 0，继续处理高位
            digits[i] = 0;
        }
        
        // 最高位仍有进位（例如 [9,9,9,9]）
        //也只有都是9才会进位嘛 ：）
        vector<int> result(n + 1, 0); // 新数组，长度 n+1，全为 0
        result[0] = 1; // 最高位为 1
        return result;
    }
};
