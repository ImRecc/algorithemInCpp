//https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1120/
class Solution {
public:
    int firstUniqChar(string s) {
    // Step 1: Create an unordered_map to store the frequency of each character
    unordered_map<char, int> frequency_map;

    // Traverse the string and count the frequency of each character
    for (char c : s) {
        frequency_map[c]++;
    }

    // Step 2: Traverse the string again to find the first unique character
    for (int i = 0; i < s.length(); i++) {
        if (frequency_map[s[i]] == 1) {
            return i;  // Return the index of the first unique character
        }
    }

    // If there is no unique character, return -1
    return -1;
    }
};
