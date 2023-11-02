//so the quick inquire need, a hashMap should be fine <- we already got one candies[i]
//what we do is: 1. find the largest num of candie
//2. traverse it & compare with largest num
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = *max_element(candies.begin(), candies.end());
        //as you can see, max_element(pointer1, pointer2) return a pointer
        //back to c again

        vector<bool> result(candies.size());
            for(int i = 0; i < candies.size(); i++)
            {
                result[i] = (greatest - candies[i] <= extraCandies);    //if are fired
            }
        return result;
    }
};


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest=candies[0];
        for (int i=1; i<candies.size(); i++)  //fine, we use size with vector
        {
            if(greatest<candies[i]) greatest=candies[i];
        }

        vector<bool> result(candies.size());    //note that different when vector(size)
                                                //or array[size]
        for (int i=0; i<candies.size(); i++)
        {
            result[i] = (greatest<=extraCandies+candies[i]) ;  
            //great. no default vale in a bool array 
            //but (only in case of global variables, it will have default value as false). 
        }
        return result;
    }
};



  
