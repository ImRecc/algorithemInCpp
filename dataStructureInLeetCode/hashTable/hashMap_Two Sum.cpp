//https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1115/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> numMap; // stores the number and its index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // find the complement
            // if complement exists in the map, return the indices
            if (numMap.find(complement) != numMap.end()) {
                return { numMap[complement], i }; // return indices of complement and current number
            }
            numMap[nums[i]] = i; // store the number and its index
        }
        return {}; // just in case, though the problem guarantees one solution
    }
};
