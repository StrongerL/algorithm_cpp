/*
快速幂求解a ^ b % c
参考：https://www.cnblogs.com/CXCXCXC/p/4641812.html

原理1：
b可以分解为若干个2的幂相加
b = b0 * 2^0 + b1 * 2^1 + b2 * 2^2 + ... + bn * 2^n; (bi = 0 or 1)
那么
a ^ b = a ^ (b0 * 2^0 + b1 * 2^1 + b2 * 2^2 + ... + bn * 2^n);
      = [a ^ (b0 * 2^0)] * [a ^ (b1 * 2^1 )] * [a ^ (b2 * 2^2 )] * ... *  [a ^ (bn * 2^n )] 
其中，(bi = 0 or 1)

原理2：
积的余数等于余数的积。


举例：
3 ^ 5 = 3 ^ (1 + 4)
      = 3 ^ 1 * 3 ^ 4
      = 243
5的二进制为101
*/

#include <iostream>
using namespace std;

int demo(int a, int b, int c) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % c;
        }
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

int main() {
    cout << demo(3, 5, 10);
}
