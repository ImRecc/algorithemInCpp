//是的没错，o(2n^2)已经很好了，对于这题，o(n^4)更是重量级,已经很可以了.jpg
//所以勿要太在意，先写再说
/*目标是找所有 a+b+c+d=0 的四元组数量。这本质上是一个组合问题，涉及四个数组的交互。暴力法是 O(n^4)，因为要枚举所有四元组，但分组 + 哈希表（比如 A+B 和 C+D）把问题拆成了两次 O(n^2) 操作，总复杂度 O(2n^2)，简化成 O(n^2)。
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 哈希表存储 A+B 的所有可能和及其出现次数
    unordered_map<int, int> sumAB;
    
    // 第一次循环：计算 A 和 B 的所有两两组合和
    for (int a : nums1) {
        for (int b : nums2) {
            sumAB[a + b]++;
        }
    }
    
    // 计数器，存储满足条件的四元组数量
    int count = 0;
    
    // 第二次循环：遍历 C 和 D，找 A+B+C+D=0 的互补和
    for (int c : nums3) {
        for (int d : nums4) {
            int target = - (c + d); // 目标和 = -(C+D)，因为 A+B+C+D=0
            if (sumAB.find(target) != sumAB.end()) {
                count += sumAB[target]; // 累加 target 出现的次数
            }
        }
    }
    
    return count;
    }
};
