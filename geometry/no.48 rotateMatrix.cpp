class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
    for (int i = 0; i < n / 2; i++) { // 只处理外层到中间
        for (int j = i; j < n-1-i; j++) { // 处理每层的元素
            // 保存当前元素
            int temp = matrix[i][j];
            // 4 次移动
            matrix[i][j] = matrix[n-1-j][i];            // (n-1-j,i) -> (i,j)
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];    // (n-1-i,n-1-j) -> (n-1-j,i)
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];    // (j,n-1-i) -> (n-1-i,n-1-j)
            matrix[j][n-1-i] = temp;                    // temp -> (j,n-1-i)
        }
    }
        
    }
};



