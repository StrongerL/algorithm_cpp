/*
https://www.nowcoder.com/practice/fd972d5d5cf04dd4bb4e5f027d4fc11e?tpId=40&tqId=21357&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

10���� VS 2����

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����5945

��Ŀ����
    ����һ��ʮ������A����Aת��Ϊ����������Ȼ��λ�������У���ת��Ϊʮ������B�����ǳ�BΪA�Ķ�������������     �������ʮ������173�����Ķ�������ʽΪ10101101���������еõ�10110101����ʮ������Ϊ181��181��Ϊ173�Ķ�������������
��������:
    һ��1000λ(��10^999)���ڵ�ʮ��������
�������:
    �����ʮ�������Ķ�������������
ʾ��1
����
173
���
181

˼·�������Ľ���ת��

*/

#include <iostream>
#define N 4010
using namespace std;

int in1[N];
int out1[N];
int in2[N];
int out2[N];

// ��һ��x���ƴ���ת����y����
int conversion(int in[], int out[], int n, int x, int y) {
    int size = 0;
    int i = 0;
    // ÿ�ε�����һ�γ���
    while (i < n) {
        int remainder = 0;
        int dividend;
        // ÿ�ε�����һλ���ֵĳ���
        for (int j = 0; j < n; j++) {
            dividend = remainder * x + in[j];
            in[j] = dividend / y;
            remainder = dividend % y;
        }
        out[size++] = remainder;
        // ��һ�γ����Ŀ�ʼλ��
        while (in[i] == 0) i++;
    }
    return size;
}


int main() {
    string s;
    while (cin >> s) {
        // ����
        int n = s.length();
        for (int i = 0; i < n; i++) {
            in1[i] = s[i] - '0';
        }

        // 10����ת��Ϊ2����
        int size = conversion(in1, out1, n, 10, 2);
        
        // ȥ�������0
        int start = 0;
        while (out1[start] == 0) start++;
        for (int i = 0; i < size - start; i++) {
            in2[i] = out1[i + start];
        }
        
        // 2����ת��Ϊ10����
        int size2 = conversion(in2, out2, size - start, 2, 10);

        // ���
        for (int i = size2 - 1; i >= 0; i--) {
            cout << out2[i];
        }
        cout << endl;
    }
}
