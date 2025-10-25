class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 二分找最接近 x 的位置
        int left = 0, right = arr.size() - 1, pos = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            pos = (abs(arr[mid] - x) < abs(arr[pos] - x) || 
                   (abs(arr[mid] - x) == abs(arr[pos] - x) && arr[mid] < arr[pos])) ? mid : pos;
            if (arr[mid] < x) left = mid + 1;
            else if (arr[mid] > x) right = mid - 1;
            else break;
        }
        
        // 双指针扩展 k 个元素
        left = pos, right = pos;
        while (right - left + 1 < k) {
            if (left == 0) { right++; continue; }
            if (right == arr.size() - 1) { left--; continue; }
            if (x - arr[left - 1] <= arr[right + 1] - x) left--;
            else right++;
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};
