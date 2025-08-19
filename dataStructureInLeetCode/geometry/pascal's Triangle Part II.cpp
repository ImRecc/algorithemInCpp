/*原理：每新行的元素row[i],i>0,都是row[i]+=row[i-1], （反着加来避免边界问题）
所以先造rowIndex+1个全是1的元素的数组（从0开始算rowIndex）
然后从每一行（外循环每一次）开始构造元素就成了）*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1); // 初始化长度 rowIndex+1，全 1 rowIndex 是0-index，start from 0
    //up from the zero~ up from the zero🎶
        for (int i = 1; i <= rowIndex; i++) { // 外循环：第 1 到 rowIndex-1 行 
            for (int j = i - 1; j >= 1; j--) { // 内循环：更新 j=1 到 i-1
                row[j] = row[j] + row[j - 1]; // C(i,j) = C(i-1,j) + C(i-1,j-1)
            }
        }
        return row;
    }
};
