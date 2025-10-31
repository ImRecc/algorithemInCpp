//二分从1-n里找根，大了动右边小了动左边，最终找不到就是无整数根
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        
        long long left = 1, right = num;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            //神奇的是int会导致5/2=2，向下取整了
            long long sq = mid * mid;
            
            
            if (sq > num) 
                //比if mid*mid=num好在防止潜在溢出
            {
                right = mid - 1;           // mid*mid > num
            } 
            else if (sq < num) 
            {
                left = mid + 1;            // mid*mid < num
            } 
            else {
                return true;               // mid*mid == num
            }
        }
        return false;
    }
};
