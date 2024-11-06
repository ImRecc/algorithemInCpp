//https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1178/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> elementCount;  // Map to store counts of elements in nums1
        vector<int> result;  // Vector to store the intersection result
        
        // Count occurrences of each element in nums1
        for (int num : nums1) {
            elementCount[num]++;
        }
        
        // Traverse nums2 and check if element exists in nums1's map
        for (int num : nums2) {
            if (elementCount[num] > 0) {  // If element exists in map and count is positive
                result.push_back(num);     // Add to result
                elementCount[num]--;       // Decrease count in map
            }
        }
        
        return result;
    }
};
