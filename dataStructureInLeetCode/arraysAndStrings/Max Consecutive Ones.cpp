class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0; // 最大连续 1 长度
        int count = 0; // 当前连续 1 长度
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++; // 遇到 1，计数+1
                maxCount = max(maxCount, count); // 更新最大值
            } else {
                count = 0; // 遇到 0，重置计数
            }
        }
        return maxCount;
    }
};
