//那单调不减数组啦，参考removeElement.cpp
//把慢指针和快指针间隔的元素全是需要改的（快指针用来找慢指针处需要的元素）
//快指针继续找，触碰边界了就把慢指针右边的全删了
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // 空数组
        int slow = 1; // 慢指针，从 1 开始（保留 nums[0]）
        for (int fast = 1; fast < nums.size(); fast++) { // 用 fast++，符合你的习惯
            if (nums[fast] != nums[fast - 1]) { // 非重复元素
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow; // 新长度 同时fast为了避免0-1=-1从1开始也正好能当计数器了
    }
};
