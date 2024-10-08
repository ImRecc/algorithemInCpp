class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mapList1;
        vector<string> result;
        int minIndexSum = INT_MAX;
        
        // Store the strings from list1 in a hash map with their indices.
        for (int i = 0; i < list1.size(); ++i) {
            mapList1[list1[i]] = i;
        }
        
        // Traverse list2, check for common strings and calculate index sum.
        for (int j = 0; j < list2.size(); ++j) {
            if (mapList1.find(list2[j]) != mapList1.end()) {
                int indexSum = j + mapList1[list2[j]];
                
                // If it's a smaller index sum, update the result.
                if (indexSum < minIndexSum) {
                    result.clear(); // Clear previous results
                    result.push_back(list2[j]);
                    minIndexSum = indexSum;
                } 
                // If it matches the smallest index sum, add to the result.
                else if (indexSum == minIndexSum) {
                    result.push_back(list2[j]);
                }
            }
        }
        
        return result;
        
    }
};
