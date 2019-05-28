/*
https://www.nowcoder.com/practice/9324a1458c564c4b9c4bfc3867a2aa66?tpId=40&tqId=21347&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

求root(N, K)

时间限制：1秒 空间限制：65536K 热度指数：5441

题目描述
    N<k时，root(N,k) = N，否则，root(N,k) = root(N',k)。N'为N的k进制表示的各位数字之和。输入x,y,k，输出root(x^y,k)的值 (这里^为乘方，不是异或)，2=<k<=16，0<x,y<2000000000，有一半的测试点里 x^y 会溢出int的范围(>=2000000000) 
输入描述:
    每组测试数据包括一行，x(0<x<2000000000), y(0<y<2000000000), k(2<=k<=16)
输出描述:
    输入可能有多组数据，对于每一组数据，root(x^y, k)的值
示例1
输入
4 4 10
输出
4


另外一种解法
https://blog.csdn.net/merlini_/article/details/50651349

*/

#include <iostream>
using namespace std;

int x, y, k;

// root(x, y, k) = x ^ y % (k - 1) 或者 k - 1，然后快速幂求解
int r(int x, int y, int k) {
    k--;
    int res = 1;
    x = x % k;
    while (y) {
        if (y & 1)
            res = res * x % k;
        x = x * x % k;
        y >>= 1;
    }
    return res;
}

int main() {
    while (cin >> x >> y >> k) {
        int res = r(x, y, k);
        if (res == 0)
            cout << k - 1 << endl;
        else
            cout << res << endl;
    }
}
