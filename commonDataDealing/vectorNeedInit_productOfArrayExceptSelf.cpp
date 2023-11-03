//set a new array that booundary as 1 like 1,2,3,4 -> 1,1,2,3,4,1
//product of all other numbers like flowerbed quest but implements to all others
//however, this gonna be o(n*(n-1)) because for each element, we iterat array...

//why not try o(n+n) like multply prefix than multply post via two for loop? 
//note that every num.at(i) equls to product of pre i * post i
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> tempVector;
        //we don't need format like 1,xxx,1
        //prefix of begin and postfix of end are them self, single condition test can do it
        //then, we count every prefix
        int timer = nums.size();
        tempVector.push_back(1); //init..note that num.at(0) doesn't have prefix
        for (int i=1; i<timer; i++) //why start from 1? cause prefix are begin() itself
        {
            tempVector.push_back(tempVector.at(i-1)*nums.at(i-1));
            //note that num.at(0) doesn't have prefix

            //caution, unlike java, a vector<int> cant vector.at(i) if not init
        }
        //then postfix
        int postfix=1; //we dont need to store postFix, 1=postOf(end) (multplication)
                       //consider as postfixOf at(3)=1;
        for (int i=timer-1; i>=0; i--)
        {
            tempVector.at(i) *= postfix;        //ans=prefix*postfix
            postfix *= nums.at(i);              //next time at(i-1) will use post
                                                //exm: at(3-1) post = at(3)*at(4) = 1*notGoningMult
        }
        
        return tempVector;
    }

};
