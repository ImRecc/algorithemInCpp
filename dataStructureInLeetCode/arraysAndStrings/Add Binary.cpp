//sum 是用来做一个a[i]和b[j]的加法后结果的数字，sum % 2 要么等于0要么等于1（不是奇数就是偶数，1+1=2 % 2 = 0， 1+0 % 2 = 1, 0+0 % 2 = 0) carry 要么等于2/2 = 1 要么就是 1或者0 /2 = 0，
class Solution {
public:
    string addBinary(string a, string b) {
        string result; // 结果字符串，类似武器能量序列
        int i = a.size() - 1; // a 的末尾指针
        int j = b.size() - 1; // b 的末尾指针
        int carry = 0; // 进位，初始为 0
        
        // 从右到左逐位相加
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // 当前和 = 进位
            if (i >= 0) sum += a[i--] - '0'; // 加上 a[i]（转为数字）
            if (j >= 0) sum += b[j--] - '0'; // 加上 b[j]（转为数字）
            result.push_back(sum % 2 + '0'); // 当前位：sum % 2，转为字符
            carry = sum / 2; // 进位：sum / 2（0 或 1）
        }
        
        // 反转结果（从右到左构造）
        reverse(result.begin(), result.end());
        return result;
    }
};
