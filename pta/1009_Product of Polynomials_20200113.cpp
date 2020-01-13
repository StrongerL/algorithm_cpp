/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344


题目
1009 Product of Polynomials (25分)


思路
怎么说呢，状态真的差，可能是因为颓了太久了吧，if (b[j] != 0) 硬是写成了if (j != 0) 。。。
*/


#include <iostream>
#include <iomanip>
using namespace std;
double a[1010];
double b[1010];
double c[2010];
int K1, K2, exp;

int main() {
    cin >> K1;
    for (int i = 0; i < K1; i++) {
        cin >> exp;
        cin >> a[exp];
    }
    cin >> K2;
    for (int i = 0; i < K2; i++) {
        cin >> exp;
        cin >> b[exp];
    }
    for (int i = 0; i < 1009; i++) {
        if (a[i] != 0) {
            for (int j = 0; j < 1009; j++) {
                if (b[j] != 0) {
                    c[i + j] += a[i] * b[j];
                }
            }
        }
    }
    int K3 = 0;
    for (int i = 2009; i >= 0; i--) {
        if (c[i] != 0) {
            K3++;
        }
    }
    cout << K3;
    for (int i = 2009; i >= 0; i--) {
        if (c[i] != 0) {
            cout << " " << i << " " << fixed << setprecision(1) << c[i];
        }
    }
}
