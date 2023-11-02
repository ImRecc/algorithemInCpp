//we used a hash map for quick inquire reason
//commonly dataStructure trade time with spaces.
class Solution{
public:
	vector <int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> hashMap;
		for (int i=0; i<nums.size(); i++) //simply .size() better than c
		{				  //note that .size() other .length() of an array
			hashMap[nums[i]] = i;	  //index: No.i content: nums[i]
		}
		//goal: find complement number if exist
		//AND!! avoid if the number are same position the coup is
		
		for (int i=0; i<nums.size(); i++)
		{
			int complement = target - nums[i];
			//if(hashMap[complement]) return {hashMap[complement], i}
			//this is a traditional error occur over counted same number
			if(hashMap[complement] && hashMap[complement] != i)
			{
				return {hashMap[complement], i};
			}
		}
		return {}; //return {}, simply and clear in C++ for arrya
			   //smarter and better than trans pointer like C dose
	}
};
