/*计算 mid = left + (right - left) / 2（防溢出，）。
判断 mid 在哪段升序：若 nums[mid] >= nums[0]：mid 在前段升序（如 [4,5,6,7]）。
若 nums[mid] < nums[0]：mid 在后段升序（如 [0,1,2]）。
*/
//然后根据 target 和 nums[mid] 的大小，决定搜哪半
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
           int left = 0, right = nums.size() - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            
            // mid 在前段升序
            if (nums[mid] >= nums[left]) 
            {
                if (nums[left] <= target && target < nums[mid]) //target大于这一半且在这一半的范围内
                {
                    right = mid - 1; // target 在前段
                } else 
                {
                    left = mid + 1; // target 在后段
                }
            }
            // mid 在后段升序
            else {
                if (nums[mid] < target && target <= nums[right]) 
                {
                    left = mid + 1; // target 在后段
                } else 
                {
                    right = mid - 1; // target 在前段
                }
            }
        }
        return -1;
    }
};
