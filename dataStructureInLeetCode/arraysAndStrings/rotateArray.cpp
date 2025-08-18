/* 三反转法在下面：向右旋转 k 步：元素 nums[i] 移到 (i + k) % n。
观察：[1,2,3,4,5], k=2 → [4,5,1,2,3]：后 k=2 个元素（4,5）移到开头。
前 n-k=3 个元素（1,2,3）移到后面
[1,2,3,4,5] 反转 → [5,4,3,2,1]。
后 k=2 元素（5,4）出现在开头，但顺序相反。
前 n-k=3 元素（3,2,1）在后面，顺序也相反。
反转前 k：[5,4,3,2,1] → [4,5,3,2,1]，前 k=2 变成正确顺序（4,5）。
反转后 n-k：[4,5,3,2,1] → [4,5,1,2,3]，后 n-k=3 变成正确顺序（1,2,3）。
结果：后 k 个元素移到开头，前 n-k 个移到后面，顺序正确。
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // 规范化 k
        if (k == 0) return;
        
        int count = 0; // 计数器
        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (current != start);
        }
    }
};

//三反转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // 规范化 k
        if (k == 0) return;
        // 三反转
        reverse(nums, 0, n - 1); // 整体反转
        reverse(nums, 0, k - 1); // 前 k 个
        reverse(nums, k, n - 1); // 后 n-k 个
    }
private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};




