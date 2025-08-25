class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 三个哈希表（unordered_set 记录数字）
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);//只考虑9个，看题目
        
        // 遍历 9x9 棋盘
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue; // 跳过空格
                char num = board[i][j];
                
                // 区块索引
                int box_idx = (i / 3) * 3 + j / 3;
                //公式将 (i,j) 坐标压缩为 0-8，确保每个格子正确对应区块。
                
                // 检查冲突
                if (rows[i].count(num) || cols[j].count(num) || boxes[box_idx].count(num))
                    return false;
                //检查 rows[i]（第 i 行的 unordered_set）是否包含字符 num（如 '1' 到 '9'）

                // 记录数字
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box_idx].insert(num);
                //map[sorted_s].push_back(s) 用于分组变位词。
                //数独：rows[0].insert('5') → 记录第 0 行有数字 5，自动去重
                //变位词：map["aet"].push_back("eat") → 将 "eat" 加到键 "aet" 的向量，存 ["eat", "tea"]。


            }
        }
        return true;
    }
};
