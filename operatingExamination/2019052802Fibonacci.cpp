/*
http://poj.org/problem?id=3070

题意：使用矩阵运算计算斐波那契数列

思路：定义好运算直接套用快速幂

此外：该题我写的有些繁琐，不必定义class的，直接用数组就行了，需要将问题泛化时再定义就可以。
*/

#include <iostream>
using namespace std;

int mod = 10000;
int n;
class M {
    public:
        int m[2][2];
};
M res;

M mul(M m1, M m2) {
    M res;
    res.m[0][0] = ((m1.m[0][0] % mod) * (m2.m[0][0] % mod) + (m1.m[0][1] % mod) * (m2.m[1][0] % mod)) % mod;
    res.m[0][1] = ((m1.m[0][0] % mod) * (m2.m[0][1] % mod) + (m1.m[0][1] % mod) * (m2.m[1][1] % mod)) % mod;
    res.m[1][0] = ((m1.m[1][0] % mod) * (m2.m[0][0] % mod) + (m1.m[1][1] % mod) * (m2.m[1][0] % mod)) % mod;
    res.m[1][1] = ((m1.m[1][0] % mod) * (m2.m[0][1] % mod) + (m1.m[1][1] % mod) * (m2.m[1][1] % mod)) % mod;
    return res;
}

void f() {
    M base;
    base.m[0][0] = 1;
    base.m[0][1] = 1;
    base.m[1][0] = 1;
    base.m[1][1] = 0;

    res.m[0][0] = 1;
    res.m[0][1] = 0;
    res.m[1][0] = 0;
    res.m[1][1] = 1;

    while (n) {
        if (n & 1) {
            res = mul(base, res);
        }
        base = mul(base, base);
        n >>= 1;
    }
}



int main() {
    while (cin >> n && n != -1) {
        if (n == 0) {
            cout << 0 << endl;
        } else {
            f();
            cout << res.m[0][1] << endl;
        }
    }
}
