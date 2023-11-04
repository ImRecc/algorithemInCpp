//point: if a+b=k, but no b record in hashMap
//then record a, cause when we traversed to b soon, we are going to use a
//and a's counter are hash[a], which +1 back when we meet a and no b around
//this even avoid over counted
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int counter=0;
        int size=nums.size();
        for (int i=0; i<size; i++)
        {
            if(hash[k-nums[i]] > 0)
            {
                hash[k-nums[i]]--;
                counter++;
            }
            else
            {
                hash[nums[i]]++;        //note that hash[a]=b
                                        //in this case, a are key, b are a's frequncy
            }
        }
        return counter;
    }
};
