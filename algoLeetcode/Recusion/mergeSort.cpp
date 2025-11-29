/*基本思路就是拆成单个后
两两对比组成拍好序的组
然后组间对比
两两对比并排序和组间对比并排序的规则是一样的
*/
class Solution {
public:
    vector<int> temp;  // 全局临时数组，省空间
    
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;               // ① 分到最小可分的单个
        
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);           // ② 左半部分继续拆
        mergeSort(nums, mid + 1, r);       // ② 右半部分继续拆
        
        //递归或者说合并有意思的地方就在于
        //被合并的元素是从更低一级的递归里返回的结果
        //尝试直接从底线情况（也就是被拆到单个元素后）发生什么开始思考递归结构会简单很多
        
        // ③ 开始合并，和邻居比对
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];     // 小的放前面
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= r)   temp[k++] = nums[j++];
        
        // 把临时数组抄回去
        for (int p = 0; p < k; p++) {
            nums[l + p] = temp[p];
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
