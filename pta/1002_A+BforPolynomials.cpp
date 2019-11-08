/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000

思路
相同指数的系数相加即可，注意输出需要保留一位小数
*/

#include <iostream>
#include <iomanip>
using namespace std;

double num1[1010];
double num2[1010];
double sum[1010];
int k1, k2, k_sum;

int main() {
    int index;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        cin >> index;
        cin >> num1[index];
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> index;
        cin >> num2[index];
    }
    for (int i = 0; i < 1001; i++) {
        sum[i] = num1[i] + num2[i];
        if (sum[i]) k_sum++;
    }

    cout << k_sum;
    if (k_sum == 0)
        return 0;
    cout << " ";
    for (int i = 1000; i >= 0; i--) {
        if (sum[i]) {
            k_sum--;
            cout << i << " " << fixed << setprecision(1) << sum[i];
            if (k_sum)
                cout << " ";
        }  
    }
}
