// pivot = j; totalSum N - leftSum == rightSum
//leftSum = i[j-1] + leftSum
//rightSum = N-leftSum
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // Step 1: 计算数组总和 N
        long long totalSum = 0; // 用 long long 防止溢出（nums[i] 范围 [-1000, 1000]）
        for (int num : nums) {
            totalSum += num;
        }
        
        // Step 2: 遍历数组，维护左边和，检查右边和
        long long leftSum = 0; // 初始化左边和为 0
        for (int j = 0; j < nums.size(); j++) {
            // 右边和 = 总和 - 当前元素 - 左边和
            long long rightSum = totalSum - nums[j] - leftSum;
            // 检查左边和是否等于右边和
            if (leftSum == rightSum) {
                return j; // 找到中间索引，返回 j
            }
            // 更新左边和，包含当前元素 nums[j]
            leftSum += nums[j];
        }
        
        // Step 3: 未找到中间索引，返回 -1
        return -1;
    }
};
