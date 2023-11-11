//feels like prefix or postfix like pazzle
//it is, but we can create a slider which length equals required averages'
//note that an average num == 1+2+3+..+n / n 
//when slider move, leave 1 alone and plus n+1
//use the max() finction well to record maxNums.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    double currSum = 0;
    for (int i = 0; i < k; i++) 
    {
        currSum += nums[i];
    }
    
    double maxSum = currSum;
    for (int i = k; i < nums.size(); i++) 
    {
        currSum = currSum - nums[i - k] + nums[i];
        maxSum = max(maxSum, currSum);
    }
    
    return maxSum / k;
    }
};
