/*
从 0 号房开始，入队 toVisit（队列）。
出队当前房间，拿其钥匙（rooms[curr]），将钥匙指向的房间入队。
访问前检查是否已访问（用哈希表或集合记录）。
记录访问过的房间（哈希表或集合）。
队列空时，检查访问房间数是否等于 n。
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited = {0}; // 已访问房间
        queue<int> toVisit; // 待访问房间
        toVisit.push(0);
        
        while (!toVisit.empty()) {
            int curr = toVisit.front(); toVisit.pop();
            for (int room : rooms[curr]) { // 遍历钥匙
                if (!visited.count(room)) { // 未访问
                    visited.insert(room);
                    toVisit.push(room);
                }
            }
        }
        return visited.size() == n;
    }
};
