## https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1147/
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxVal = 0; // 最大值
        int secondMax = 0; // 次大值
        int maxIndex = -1; // 最大值索引
        int n = nums.size(); // 数组长度
        
        // Step 1: 遍历数组，找到最大值和次大值
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxVal) {
                // 当前值 > 最大值，更新次大值和最大值
                secondMax = maxVal;
                maxVal = nums[i];
                maxIndex = i;
            } else if (nums[i] > secondMax) {
                // 当前值 <= 最大值，但 > 次大值，更新次大值
                secondMax = nums[i];
            }
        }
        
        // Step 2: 检查最大值是否至少是次大值的两倍
        // n=1 时无需比较，直接返回 0
        if (n == 1 || maxVal >= 2 * secondMax) {
            return maxIndex;
        }
        
        // Step 3: 不满足条件，返回 -1
        return -1;
    }
};
