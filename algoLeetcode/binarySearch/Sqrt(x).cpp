//rounded down to the nearest integer，so like 8, when comes to 2,3, we can almost end for 2
//do binary search from n to 0 (non negative nums)
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x; // 边界
        int left = 0, right = min(x, 46340); // 46340^2 ≈ 2^31
        int ans = 0;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            /*这样等价为left/2+right/2=left+right /2
            但是直接用可能会超出边界，int边界，导致溢出
            */
            if (mid <= x / mid) // mid * mid <= x to check if meet
            { 
                ans = mid; // 记录候选
                left = mid + 1;
            } else 
            {
                right = mid - 1;
            }
            /*二分查找的核心：每次检查中间点 mid，根据比较结果排除一半范围。
            排除的依据是数组（或范围）单调性（如 #69 的 k*k 递增）。
            目标：缩小 [left, right] 直到 left > right，找到答案或确定无解。

            为什么加减 1：mid 已被检查（nums[mid] 或 mid * mid），无需再次包含。
            若不加减（如 right = mid 或 left = mid），mid 留在范围内，可能导致重复检查，陷入死循环。
            */

        }
        return ans;
    }
};
