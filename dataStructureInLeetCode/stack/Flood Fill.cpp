/*类似前面的BFS-number of islands
只是这个涉及到改数值
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image; // 无需修改
        int m = image.size(), n = image[0].size();
        queue<pair<int,int>> toVisit; // 待处理点
        toVisit.push({sr, sc});
        image[sr][sc] = newColor; // 标记起始点
        
        vector<pair<int,int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}}; // 四向
        while (!toVisit.empty()) {
            auto [r, c] = toVisit.front(); toVisit.pop();
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == oldColor) {
                    image[nr][nc] = newColor; // 标记
                    toVisit.push({nr, nc});
                }
            }
        }
        return image;
    }
};
