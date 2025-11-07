class Solution {
    unordered_map<int, int> memo;
public:
    int fib(int n) {
        if (n <= 1) return n;
        if (memo.count(n)) return memo[n]; //比如Fib(4)会计算到Fib(3)，那么这一次记录下Fib(3)和本体Fib(4)
        //下一次算Fib(5)，传入Fib(4)和Fib(3)就可以直接从哈希表里拿了
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
};
