//https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1168/
// 解法：按顺时针螺旋顺序遍历矩阵，类似 UE5 2D 武器网格沿边缘收集能量。
// 方法：分层遍历（借鉴 LeetCode 48 旋转矩阵），维护 top/bottom/left/right 边界，
// 每层按右->下->左->上遍历，缩小边界，重复直到访问 m*n 个元素。
// 时间：O(m*n)，空间：O(1)（不计输出）。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); // 行数
        int n = matrix[0].size(); // 列数
        vector<int> result; // 结果数组
        int top = 0, bottom = m - 1; // 上下边界
        int left = 0, right = n - 1; // 左右边界
        
        while (top <= bottom && left <= right) {
            // 右：(top, left) -> (top, right)
            for (int j = left; j <= right && top <= bottom; j++) {
                result.push_back(matrix[top][j]);
            }
            top++; // 缩小上边界
            
            // 下：(top, right) -> (bottom, right)
            for (int i = top; i <= bottom && left <= right; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // 缩小右边界
            
            // 左：(bottom, right) -> (bottom, left)
            for (int j = right; j >= left && top <= bottom; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--; // 缩小下边界
            
            // 上：(bottom, left) -> (top, left)
            for (int i = bottom; i >= top && left <= right; i--) {
                result.push_back(matrix[i][left]);
            }
            left++; // 缩小左边界
        }
        
        return result;
    }
};
