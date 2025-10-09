/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
//标准模板属于

int guess(int num);

class Solution {
public:
    int guessNumber(int n) 
    {
        int left = 1, right = n;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2; // 防溢出
            int result = guess(mid);
            if (result == 0) return mid;
            if (result == 1) left = mid + 1; // 太小，搜右半
            else right = mid - 1; // 太大，搜左半
        }
        return left; // 理论上不会到这步
    }
};
