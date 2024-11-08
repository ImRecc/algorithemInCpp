class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numIndexMap; // Stores the number and its last seen index

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            // Check if the number is already in the map and if the difference between indices is ≤ k
            if (numIndexMap.find(num) != numIndexMap.end() && (i - numIndexMap[num] <= k)) {
                return true;
            }

            // Update the index of the current number in the map
            numIndexMap[num] = i;
        }

        return false; // No duplicates found within the required range
    }
};
