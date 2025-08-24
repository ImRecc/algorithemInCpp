class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { //作用：在函数参数 vector<string>& strs 中，
        //& 表示引用（reference），是 C++ 的语言特性，用于避免复制大对象（
        //如 vector），提高性能，同时允许直接访问调用者的 strs 数据。


        // unordered_map 提供 O(1) 平均插入/查询，适合快速分组
        // Key=排序后的字符串（如"aet"），Value=原词列表（如["eat", "tea"]）
        unordered_map<string, vector<string>> map;

        // 遍历输入数组
        for (string s : strs) {
            // 字符串s在字符串数组strs里遍历啦
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); // O(k * log k)，k=字符串长度
            //把字符串排序一下


            // map[sorted_s] 自动创建空vector（语言特性：operator[]）
            // push_back 添加原词到列表
            map[sorted_s].push_back(s);
            //以排序好的字符串为键，对应的值是乱序的字符串组成的数组（vector<string>）;
            //aet: ate, eat, tea，abt: bat;这个样子
        }

        // 收集结果
        // unordered_map 的值需转为 vector<vector<string>>
        vector<vector<string>> result;
        for (auto& pair : map) //for (pair<const string, vector<string>>& pair1 : map)
        //哈希表没有传统“索引”（如 vector 的 a[0]），pair 是键值对的引用，表示 map 的一个条目（entry）。
        //pair: pair<const string, vector<string>>
        //for (auto& i : a) 适用于任何支持迭代器的容器（如 vector, map, set, array 等）。
        //无 &（如 for (auto i : a)）：i 是值拷贝，适合只读，修改不影响原容器。
        //用 &：i 是引用，适合修改或大对象（避免复制）。
        //


        {
            // 语言特性：pair.second 是值（vector<string>）
            result.push_back(pair.second);
        }

        return result;
    }
};
