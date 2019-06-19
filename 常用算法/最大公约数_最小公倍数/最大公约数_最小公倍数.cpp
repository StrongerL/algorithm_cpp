#include <iostream>
using namespace std;

// �����Լ����Greatest Common Divisor��GCD��
// ���
int gcd1(int a, int b) {
    int c = a > b ? b : a;
    while (a % c != 0 || b % c != 0) {
        c--;
    }
    return c;
}


// �������
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


// շת�����
int gcd3(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}


// ����С������(least/lowest common multiple��LCM)
int lcm(int a, int b) {
    return a * b / gcd1(a, b);
}


int main() {

    // ���������
    // ���
    cout << gcd2(12, 9) << endl;
    cout << gcd2(18, 12) << endl;
    cout << gcd2(13, 3) << endl;
    cout << endl;

    // �������
    cout << gcd2(12, 9) << endl;
    cout << gcd2(18, 12) << endl;
    cout << gcd2(13, 3) << endl;
    cout << endl;

    // շת�����
    cout << gcd2(12, 9) << endl;
    cout << gcd2(18, 12) << endl;
    cout << gcd2(13, 3) << endl;
    cout << endl;


    // ����С������
    cout << lcm(12, 9) << endl;
    cout << lcm(18, 12) << endl;
    cout << lcm(13, 3) << endl;
    cout << endl;

}
