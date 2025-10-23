//单调性
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2; // 防溢出
            if (nums[mid] > nums[right]) {
                left = mid + 1; // 最小值在右半
            } else {
                right = mid; // 最小值在左半（包括 mid）
            }
        }
        return nums[left]; // 最小值
    }
};
