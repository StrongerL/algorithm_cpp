/*
���ַ�ת

https://www.nowcoder.com/practice/2687c5c174cb4f938bdae01f0a19490c?tpId=40&tqId=21428&tPage=5&rp=5&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����3673

��Ŀ����
    12��һ����21,34��һ����43,12+34��46,46��һ����64��������������������������������������ת�ĺ��Ƿ�����������ĺ͵ķ�ת��
��������:
ÿ������������a��b��0<a,b<=10000����
�������:
    ���������Ŀ��Ҫ�����a+b��ֵ���������NO��
ʾ��1
����
12 34
99 1
���
46
NO

 */

#include <iostream>
#include <string>
using namespace std;

string a, b, s1, s2;

void swapMethod(string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char tmp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = tmp;
    }
}

int main() {
    while (cin >> a >> b) {
        int a1 = stoi(a);
        int b1 = stoi(b);
        int sum1 = a1 + b1;
        s1 = to_string(sum1);
        swapMethod(s1);
        
        swapMethod(a);
        swapMethod(b);
        int a2 = stoi(a);
        int b2 = stoi(b);
        int sum2 = a2 + b2;
        s2 = to_string(sum2);
        
        if (s1 == s2) {
            cout << a1 + b1 << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
}
