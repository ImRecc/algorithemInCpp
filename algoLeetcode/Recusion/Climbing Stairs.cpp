class Solution {
    unordered_map<int, int> memo;
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (memo.count(n)) return memo[n];
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};
//反向斐波那契数列属于
//然后用哈希表储存已经验证过的序列也是经典
//再解释下这个储存已验证是如何节省的：比如n=5，n-1=4 n-2=3，然后对后者会先一步触碰到n=1和n=2，所以n=3的情况可以在n=4的处理中直接使用
