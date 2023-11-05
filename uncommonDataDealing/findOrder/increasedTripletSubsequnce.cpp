//334. Increasing Triplet Subsequence

//interesting pazzle

//no matter how the smallest element change
//we need one second small element shows up
//!! the second one are marks as a symbol of someone smaller than it

//same, no matter how first or second one change, the order are exist and detected

//when third spotted, we are done;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX;        // INT_MAX or INT_MIN
    int second = INT_MAX;       //like they literal

    for (const int num : nums)  //so proger cannot modifie
      if (num <= first)
        first = num;
      else if (num <= second)  // once shows up, the order detected
        second = num;          //can record like first.now<second.now
      else
        return true;  // once shows up, the order detected too
                      //but the sequnce? have to record when second changed  

    return false;
  }
};

