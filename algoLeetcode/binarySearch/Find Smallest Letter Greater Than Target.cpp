//如果全列都没有大于目标的就返回第一个元素，然后由于left=mid+1且仅在left=right时候才返回，所以也不用担心left不能表示正确的位置


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();  // 注意：right = n
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) 
            {
                left = mid + 1;   // 继续找更大的
            } else 
            {
                right = mid;      // 可能是答案，搜左边
                //条件是是否不大于，如果mid大于了那可能是解嘛
            }
        }
        // left == right，left 是大于 target 的最小索引
        return left < letters.size() ? letters[left] : letters[0];
    }
};
