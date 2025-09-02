/*values 是一个 vector<int>（动态数组），存储 RandomizedSet 中的所有元素（如 [1, 2]）。
配合 valToIndex（unordered_map<int, int>，存储 <值, 索引>）实现 O(1) 操作：插入：values.push_back(val) 添加新值，valToIndex[val] = values.size() - 1 记录索引。
删除：用末尾值覆盖要删除的位置（values[index] = values.back()），然后 pop_back()。
随机获取：getRandom() 用 rand() % values.size() 随机索引，O(1) 访问。
*/

class RandomizedSet {
    unordered_map<int, int> valToIndex; // <值, 数组索引>
    vector<int> values; // 存储所有值
public:
    RandomizedSet() {
        // 初始化
        //// 初始化空哈希表和数组
        // 什么也不做，因为 valToIndex 和 values 默认空
    }
        
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        values.push_back(val); //values 数组才是用来存储数据的那个
        valToIndex[val] = values.size() - 1; //索引有哈希表记录
        return true;
    }//哈希表塞新东西，记录索引的数组实现方法
    //因为索引是后给的，值倒是传进来，所以这么搞，而不是hash[index]=val;
    //也就是说这里传入的值是键，对应的值是这个值的索引“键”
    
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        int index = valToIndex[val];  //val的键
        int lastVal = values.back(); //vector还能这么玩啊
        //直接访问 values[values.size() - 1]，返回实际存储的值（如 int）
        values[index] = lastVal;    //索引处的值被lastVal替代
        valToIndex[lastVal] = index; //记得哈希表是<传入值，值的索引>结构么，这样来更新下已经挪位置的lastVal的索引
        values.pop_back();          //把目前的最后一个值（已经和之前的最后一个值互换了）弹出
        valToIndex.erase(val);      //是的，哈希表能erase
        return true;
    }
    //用新的数组存储这些需要删、增的值，然后
    
    int getRandom() {
        return values[rand() % values.size()];
    }
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
