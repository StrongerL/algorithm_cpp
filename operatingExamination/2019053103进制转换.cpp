/*
https://www.nowcoder.com/practice/0337e32b1e5543a19fa380e36d9343d7?tpId=40&tqId=21361&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

����ת��

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����8973

��Ŀ����
��һ���������Ϊ30λ���ֵ�ʮ���ƷǸ�����ת��Ϊ�������������
��������:
�������ݣ�ÿ��Ϊһ�����Ȳ�����30λ��ʮ���ƷǸ�������
��ע����10�������ֵĸ���������30��������30bits��������
�������:
ÿ�������Ӧ�Ķ���������
ʾ��1
����
0
1
3
8
���
0
1
11
1000

˼·�������Ľ���ת�����ο���ҳ��https://blog.csdn.net/sjf0115/article/details/8690581?utm_source=copy

*/

#include <iostream>
using namespace std;

int n;
string s;
int in[40];
int out[120];

int conversion() {
    int size = 0;
    int i = 0;
    // ÿ�ε�����һ�γ���
    while (i < n) {
        int remainder = 0;
        int quotient;
        int dividend;
        // ÿ�ε�����һλ���ֵĳ���
        for (int j = i; j < n; j++) {
            dividend = remainder * 10 + in[j];
            remainder = dividend % 2;
            quotient = dividend / 2;
            in[j] = quotient;
        }
        out[size++] = remainder;
        // ��һ�γ����Ŀ�ʼλ��
        while (in[i] == 0) i++;
    }
    return size;
}

int main() {
    while (cin >> s) {
        n = s.length();
        for (int i = 0; i < n; i++) {
            in[i] = s[i] - '0';
        }
        int size = conversion();
        for (int i = size - 1; i >= 0; i--) {
            cout << out[i];
        }
        cout << endl;
    }
}
