//要o(nLog(n))可以先排序完事diff=target-maxElemetn
//缺点是这样改变了传入的数组
//还有就是需要的是“子数组”也就是说必须是连续的
//双指针滑动着找就好了
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX; // 最小长度 最大 32 位整数，约 2^31-1），表示“未找到有效子数组”。
        int sum = 0; // 窗口和
        int left = 0; // 左指针
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right]; // 扩展窗口
            while (sum >= target) { // 找到符合条件的窗口
                minLen = min(minLen, right - left + 1); // 更新最小长度
                sum -= nums[left]; // 缩小窗口
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen; // 无解返回
    }
};
