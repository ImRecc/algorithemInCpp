//just exactly same as previous article bruh
//traverse, save non-vals, then keep slowerPointer in place to await next non-val appear
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
          int k = 0; // 慢指针
        for (int i = 0; i < nums.size(); i++) { // 快指针
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
