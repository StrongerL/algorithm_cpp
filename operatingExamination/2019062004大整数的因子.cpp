/*
������������

https://www.nowcoder.com/practice/3d6cee12fbf54ea99bb165cbaba5823d?tpId=40&tqId=21370&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����3147

��Ŀ����
��֪������k����2<=k<=9���ָ����������Ϊ30λ��ʮ���ƷǸ�����c��������������c��k.
��������:
���ɸ��Ǹ�����c��c��λ��<=30
ÿ��һ��c
�������:
ÿһ��c�Ľ��ռһ��
1) ���������� c%k == 0 ��k���������������k���м��ÿո���������һ��k����û�пո�
2) ��û��������k�����"none"

ע�������������
��Ҫ��-1���м���
ʾ��1
����
30
72
13
���
2 3 5 6
2 3 4 6 8 9
none


˼·��ʹ������洢����

 */

#include <iostream>
using namespace std;

int num[40];
int n;
string s;

string f() {
    string res = "";
    for (int i = 2; i <= 9; i++) {
        int remainder = 0;
        int dividend;
        for (int j = 0; j < n; j++) {
            dividend = remainder * 10 + num[j];
            remainder = dividend % i;
        }
        if (!remainder)
            res += i + 48;
    }
    return res;
}


int main() {
    while (cin >> s) {
        n = s.length();
        for (int i = 0; i < n; i++) {
            num[i] = s[i] - '0';
        }
        string res = f();
        if (res.length() == 0) {
            cout << "none" << endl;
            continue;
        }
        for (int i = 0; i < res.length(); i++) {
            cout << res[i];
            if (i != res.length() - 1)
                cout << " ";
        }
        cout << endl;
    }
}
