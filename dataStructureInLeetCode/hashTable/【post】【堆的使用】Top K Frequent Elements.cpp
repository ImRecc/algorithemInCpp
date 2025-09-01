/*priority_queue 是 C++ STL（标准模板库）中的优先队列，基于堆（Heap）数据结构。
默认是大顶堆（最大元素在顶部），可以用 greater<> 改为小顶堆。(频率小的在顶部)
用途：快速获取最大/最小元素，自动维护排序。
*/
//第二个是排序法
class Solution {
public:
     vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // <数值, 频率>
        for (int num : nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 小顶堆
        for (auto& [num, count] : freq) {
            
            //auto&：引用，遍历 freq 的每个键值对（避免拷贝）。
            //[num, count]：解构每个键值对，num 是键（数值），count 是值（频率）。

            pq.push({count, num});//num, count都是这个循环里由auto定义然后& [num, count]来调用freq哈希表避免拷贝的
            //{}是一个构造符呢
            if (pq.size() > k) {
                pq.pop(); // 保持堆大小为 k
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
//排序法
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq; // <数值, 频率>
    for (int num : nums) {
        freq[num]++;
    }
    vector<pair<int, int>> pairs;
    for (auto& [num, count] : freq) {
        pairs.push_back({count, num}); // 构造 pair {频率, 数值}
    }
    sort(pairs.rbegin(), pairs.rend()); // 降序排序
/*sort(pairs.begin(), pairs.end())：升序排序（频率小的在前）。
sort(pairs.rbegin(), pairs.rend())：降序排序（频率大的在前）。
*/
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(pairs[i].second);
    }
    return result;
}
