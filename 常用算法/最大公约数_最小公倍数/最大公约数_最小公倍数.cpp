#include <iostream>
using namespace std;

// 求最大公约数（Greatest Common Divisor，GCD）
// 穷举
int gcd1(int a, int b) {
    int c = a > b ? b : a;
    while (a % c != 0 || b % c != 0) {
        c--;
    }
    return c;
}


// 更相减损法
int gcd2(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}


// 辗转相除法
int gcd3(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}


// 求最小公倍数(least/lowest common multiple，LCM)
int lcm(int a, int b) {
    return a * b / gcd1(a, b);
}


int main() {

    // 求最大公因数
    // 穷举
    cout << gcd2(12, 9) << endl;
    cout << gcd2(18, 12) << endl;
    cout << gcd2(13, 3) << endl;
    cout << endl;

    // 更相减损法
    cout << gcd2(12, 9) << endl;
    cout << gcd2(18, 12) << endl;
    cout << gcd2(13, 3) << endl;
    cout << endl;

    // 辗转相除法
    cout << gcd2(12, 9) << endl;
    cout << gcd2(18, 12) << endl;
    cout << gcd2(13, 3) << endl;
    cout << endl;


    // 求最小公倍数
    cout << lcm(12, 9) << endl;
    cout << lcm(18, 12) << endl;
    cout << lcm(13, 3) << endl;
    cout << endl;

}
