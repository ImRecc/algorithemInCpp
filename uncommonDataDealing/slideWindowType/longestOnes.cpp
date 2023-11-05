//just like previous one
//upPointer, downPointer
//upPointer: mark current pos, downP to traverse and see if is 1, yes, then curentMax++
//no? k--, flip as 1(currentMax++); 

//how to flip? mark as 2, but count as 1?  we don't modify any thing
//when lp++ ==0 && k=0; up++; loop till lp=end()
//however, when k=0, and start with000, fatal error

//when downP traverse to a 0 and k=0, compare the max&currentMax;
//loop till downP meet the end, compare the max&currentMax again;

//reconstructed: counte contiouns 0,
//if overBoard like exceed to k, move upper to validize it
//clever.
class Solution {
public: 
    int longestOnes(vector<int>& nums, int k) {
        int upper = 0, lower = 0, countZeros = 0, maxConsecutiveOnes = 0;
        
        while (lower < nums.size()) 
        {
            if (nums[lower] == 0) countZeros++;
            
            while (countZeros > k) 
            {
                if (nums[upper] == 0) 
                {
                    countZeros--;
                }
                upper++;
            }
            
            maxConsecutiveOnes = max(maxConsecutiveOnes, lower - upper + 1);  //3-2=1, but 3,2=2
            lower++;
        }
        
        return maxConsecutiveOnes;
    }
};
