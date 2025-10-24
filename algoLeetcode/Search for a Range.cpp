//或者可以用后处理直接比对左右是否一致来扩大边界，但说到底不还是需要对两边继续二分么
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        // 找左边界
        int left = 0, right = nums.size() - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // 防溢出
            if (nums[mid] == target) {
                first = mid; // 记录可能左边界
                right = mid; // 搜左半
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // 找右边界
        left = 0, right = nums.size() - 1;
        int last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid; // 记录可能右边界
                left = mid + 1; // 搜右半
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return {first, last};
    }
};
