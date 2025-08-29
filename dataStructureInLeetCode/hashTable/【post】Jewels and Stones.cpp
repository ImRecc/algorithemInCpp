//有时候我真的对这种前后难度不一致的反差感到离谱
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
         unordered_set<char> check(jewels.begin(), jewels.end());
        int count = 0;
        for (char s : stones) {
            if (check.count(s)) {
                count++;
            }
        }
        return count;
    }
};
