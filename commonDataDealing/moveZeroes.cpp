//no extra space? fine, we got eraser() function for vector.
//which both delete element and decrease the container
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int counter=0;
       //auto are beautiful type, tell complier to decide type if she know
       auto iterator=nums.begin();
       //true o(n), cause we only iterator once and unlike pos<nums.size()
       //we only ask for address of nums.end()
       
       while( iterator<nums.end())        
       {    //try only iterate once
           if(*iterator==0)
           {
               nums.erase(iterator); //pos=0; once found it, 
               counter++;                   //star next time,cause erased()   
           }
           else iterator++; 
       } 
       for(int i=0; i<counter; i++)
       {
           nums.push_back(0);
       }
    }
};



//no extra space? fine, we got eraser() function for vector.
//which both delete element and decrease the container
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int counter=0, pos=0;
       while(pos<nums.size())       //try only iterate once 
       {
           if(nums.at(pos)==0)
           {
               nums.erase(nums.begin()+pos);
               counter++;
                                    //pos=0; once found it, 
                                    //star next time,cause erased()
           }
           else pos++; 
       } 
       for(int i=0; i<counter; i++)
       {
           nums.push_back(0);
       }
    }
};
