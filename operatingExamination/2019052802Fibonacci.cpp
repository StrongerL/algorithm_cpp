/*
http://poj.org/problem?id=3070

���⣺ʹ�þ����������쳲���������

˼·�����������ֱ�����ÿ�����

���⣺������д����Щ���������ض���class�ģ�ֱ������������ˣ���Ҫ�����ⷺ��ʱ�ٶ���Ϳ��ԡ�
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
