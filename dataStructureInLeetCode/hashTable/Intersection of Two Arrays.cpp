//https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1105/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // Step 1: Create a hash table (unordered_set) to store elements of nums1
        unordered_set<int> set1(nums1.begin(), nums1.end());
        
        /*We initialize a hash table (unordered_set) to store all the elements of nums1. 
        unordered_set is a built-in container in C++ that uses hashing for fast lookup and insertion 
        (constant average time complexity). 
        The constructor nums1.begin(), nums1.end() copies all elements from nums1 into the set.
        */
        
        // Step 2: Create another set to store the intersection results
        unordered_set<int> resultSet;

        // Step 3: Traverse nums2 and check if elements are in set1
        for (int num : nums2) {
            if (set1.find(num) != set1.end()) { // Element found in set1
                resultSet.insert(num); // Add to result set
            }
        }
        
        /*.count(num) checks if the element is present in the set, and if so, we insert it into resultSet.
        */

        // Step 4: Convert the result set to a vector
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};
