/*用队列存储待探索的格子（坐标 pair<int, int>）。
从当前 '1' 开始，将其加入队列，标记为已访问（改成 '0' 或用 visited 数组）。
队列不空时，取出队首格子，探索其上下左右四个方向。
若相邻格子是 '1' 且未访问，加入队列，标记访问。
*/
/*就是在历遍给的二维字符串数组grid的过程中，遇到一个1就开始以当前位置为开始，用offset来实现当前位置的四向判断，然后如果某个方向同时满足不越界且等于1，则塞入一个构造的队列里，等待判断；当然，要把当前判断的弹出，因为是队列，先进先出？虽然我也不知道用栈有什么不同？毕竟判断四个方向，成了就塞进去，不成就不塞，
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        int islandCount = 0;
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1') {
                    islandCount++; // 发现新岛屿
                    exploreIsland(grid, row, col, rows, cols); // BFS 探索
                }
            }
        }
        return islandCount;
    }
    
private:
    void exploreIsland(vector<vector<char>>& grid, int startRow, int startCol, int rows, int cols) {
        queue<pair<int, int>> toVisit; // 待访问的坐标
        toVisit.push({startRow, startCol});
        //{startRow, startCol} 是 C++ 的初始化列表，构造一个 pair<int, int> 对象。
        
        grid[startRow][startCol] = '0'; // 标记为已访问
        
        // 四个方向：上、右、下、左
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while (!toVisit.empty()) 
        {
            auto [row, col] = toVisit.front(); // 当前格子
            //auto [row, col] 是 C++17 的结构化绑定，解构 pair<int, int> 为【两个变量】 row 和 col
            //pair<int, int> pos = toVisit.front();
            //toVisit.front() 返回队列头部的 pair<int, int>（第一个坐标对）
            
            toVisit.pop();
            
            for (auto [rowOffset, colOffset] : directions) 
            {
                int nextRow = row + rowOffset, nextCol = col + colOffset;
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && grid[nextRow][nextCol] == '1') {
                    toVisit.push({nextRow, nextCol});
                    grid[nextRow][nextCol] = '0'; // 标记
                }
            }
        }
    }
};
