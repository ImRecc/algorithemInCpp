//直接来的话可能会
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long long N = n; // 防溢出
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double res = 1.0;
        double base = x;
        while (N > 0) {
            if (N % 2 == 1) { // n 是奇数
                res *= base;
            }
            base *= base; // 平方
            //不同于res*=base的循环，这个2，4，16，196..
            //比如n=16的情况，x=2，那就可以拆成2^8*2^8这样子，然后每个2^8又可以再缩成两个2^4相乘嘛
            //2^16 = (2^8)^2 = ((2^4)^2)^2 = (((2^2)^2)^2)^2
            N /= 2;       // 折半
        }
        return res;
    }
};
