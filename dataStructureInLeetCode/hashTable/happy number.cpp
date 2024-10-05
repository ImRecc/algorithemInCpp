//https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1131/
class Solution {
public:
    //think about this, a square of a numbers digits, are gonna smaller than a curtain range
    //99 => 162, 999 ->243, note in three nums, 999 is higherst
    //so 81+81+81+.... must be smaller than 99999...
    bool isHappy(int n) 
    {
        unordered_set<int> seen; // Hash table to track sums
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n); // Store the current number
            n = sumOfSquares(n); // Calculate the sum of squares
        }
        return n == 1; // Return true if happy number, false if cycle detected
    }
    
    private:
    int sumOfSquares(int num) 
    {
        int sum = 0;
        while (num > 0) 
        {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
};
