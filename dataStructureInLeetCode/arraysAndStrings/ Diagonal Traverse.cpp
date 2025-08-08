// https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1167/
//分解寻路 向上、向下，都不行分情况，很直观咯
int m = mat.size(); // 行数
        int n = mat[0].size(); // 列数
        vector<int> result; // 结果数组
        int i = 0, j = 0; // 当前坐标
        bool up = true; // 方向：true=向上(右上)，false=向下(左下)
        
        // 遍历直到收集 m*n 个元素
        while (result.size() < m * n) {
            result.push_back(mat[i][j]); // 添加当前元素
            
            if (up) {
                // 向上（右上：i-1, j+1）
                if (i - 1 >= 0 && j + 1 < n) {
                    i--; // 继续向上
                    j++;
                } else {
                    // 向上受阻
                    if (j + 1 < n) {
                        j++; // 右移
                    } else {
                        i++; // 下移
                    }
                    up = false; // 切换为向下
                }
            } else {
                // 向下（左下：i+1, j-1）
                if (i + 1 < m && j - 1 >= 0) {
                    i++; // 继续向下
                    j--;
                } else {
                    // 向下受阻
                    if (i + 1 < m) {
                        i++; // 下移
                    } else {
                        j++; // 右移
                    }
                    up = true; // 切换为向上
                }
            }
        }
        
        return result;
