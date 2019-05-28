/*
���������a ^ b % c
�ο���https://www.cnblogs.com/CXCXCXC/p/4641812.html

ԭ��1��
b���Էֽ�Ϊ���ɸ�2�������
b = b0 * 2^0 + b1 * 2^1 + b2 * 2^2 + ... + bn * 2^n; (bi = 0 or 1)
��ô
a ^ b = a ^ (b0 * 2^0 + b1 * 2^1 + b2 * 2^2 + ... + bn * 2^n);
      = [a ^ (b0 * 2^0)] * [a ^ (b1 * 2^1 )] * [a ^ (b2 * 2^2 )] * ... *  [a ^ (bn * 2^n )] 
���У�(bi = 0 or 1)

ԭ��2��
�����������������Ļ���


������
3 ^ 5 = 3 ^ (1 + 4)
      = 3 ^ 1 * 3 ^ 4
      = 243
5�Ķ�����Ϊ101
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
