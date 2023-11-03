//no extra space? fine, we got eraser() function for vector.
//which both delete element and decrease the container
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int counter=0, pos=0;
       while(pos<nums.size())
       {
           if(nums.at(pos)==0)
           {
               nums.erase(nums.begin()+pos);
               counter++;
               pos=0;
           }
           else pos++; 
       } 
       for(int i=0; i<counter; i++)
       {
           nums.push_back(0);
       }
    }
};
