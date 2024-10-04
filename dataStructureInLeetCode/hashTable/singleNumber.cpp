//https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1176/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //the Exclusively OR operation work like：
        //x ^ x = 0, x ^ 0 = x;
        //this is because the bitwise operation, 01101 like this
        
        //the mastering principle is: a^b^c = (a^c)^b, means all the other
        //a^b^c^d^c^a^b = a^a^b^b^c^c^d = 0^d = d
        int result = 0; //tokens
        //for (auto element : container)
        // Do something with element
        for (int beacon : nums)
        {
            result = result ^ beacon;
        }
        return result;
    }
};
