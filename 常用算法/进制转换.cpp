/*

    ����ת��

    ������  dividend
    ����    divisor
    ��      quotient
    ����    remainder

    �ο���ҳ�� https://blog.csdn.net/sjf0115/article/details/8690581?utm_source=copy

    ��ϰ��
    operatingExamination\2019053101_10����VS2����.cpp
    operatingExamination\2019053103����ת��.cpp

*/

#include <iostream>
using namespace std;

// x����ת��Ϊy����
int conversion(int in[], int out[], int n, int x, int y) {
    // ת��Ϊy����֮��ĳ���
    int size = 0;
    int i = 0;
    // ÿ�ε�����һ�γ���
    while (i < n) {
        int remainder = 0;
        int dividend;
        // ÿ�ε�����һλ���ֵĳ���
        for (int j = i; j < n; j++) {
            dividend = remainder * x + in[j];
            in[j] = dividend / y;
            remainder = dividend % y;
        }
        out[size++] = remainder;
        // ��һ�γ�����ʼ��λ��
        while (in[i] == 0) i++;
    }
    return size;
}


int main() {
    string s;
    int in[100];
    int out[100];
    while (cin >> s) {
        // ����
        int n = s.length();
        for (int i = 0; i < n; i++) {
            in[i] = s[i] - '0';
        }

        // 10����ת��Ϊ2����
        int size = conversion(in, out, n, 10, 2);

        // ���
        for (int i = size - 1; i >= 0; i--) {
            cout << out[i];
        }
        cout << endl;
    }
}
