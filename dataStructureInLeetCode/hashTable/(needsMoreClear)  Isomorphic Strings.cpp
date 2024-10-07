//https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1117/
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If the lengths are different, they can't be isomorphic
        if (s.length() != t.length()) return false;
        
        // Create two hash maps for bi-directional mapping
        unordered_map<char, char> mapST; // Map from s to t
        unordered_map<char, char> mapTS; // Map from t to s
        
        // Traverse the strings
        for (int i = 0; i < s.length(); i++) {
            char charS = s[i];
            char charT = t[i];
            
            // Check s -> t mapping
            if (mapST.find(charS) != mapST.end()) {
                if (mapST[charS] != charT) return false; // Conflicting mapping
            } else {
                mapST[charS] = charT; // Create a new mapping
            }
            
            // Check t -> s mapping
            if (mapTS.find(charT) != mapTS.end()) {
                if (mapTS[charT] != charS) return false; // Conflicting mapping
            } else {
                mapTS[charT] = charS; // Create a new mapping
            }
        }
        
        return true; // Strings are isomorphic
    }
};
