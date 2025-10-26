//每次检查 mid，若不是峰值，至少一侧（左或右）有更大值，可能含峰值。

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2; // 防溢出
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1; // 右半可能有峰值
            } else {
                right = mid; // mid 可能是峰值，搜左半
            }
        }
        return left; // 峰值索引
    }
};
