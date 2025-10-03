//新建的那个距离二维数组，是0的就写0，不是0的保持INI_MAX
//在BFS里，对INI_MAX的元素进行四向历遍，也就是说至少有1的距离到0
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX)); // 距离
        //构造一个rows*cols的二维数组dist, 每个元素都是INT_MAX;
        queue<pair<int,int>> toVisit; // 待处理
        vector<pair<int,int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}}; // 四向
        
        // 初始所有 0
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 0) 
                {
                    dist[row][col] = 0;
                    toVisit.push({row, col});
                }
            }
        }
        
        // BFS
        while (!toVisit.empty()) 
        {
            auto [row, col] = toVisit.front(); toVisit.pop();
            for (auto [dr, dc] : dirs) 
            {
                int newRow = row + dr, newCol = col + dc;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
                    dist[newRow][newCol] == INT_MAX) 
                    //对没有被列为0的（也就是需要找距离0有多远的元素检测
                {
                    dist[newRow][newCol] = dist[row][col] + 1;
                    //被检测到的至少为1嘛
                    toVisit.push({newRow, newCol});
                }
            }
        }
        return dist;
    }
};
