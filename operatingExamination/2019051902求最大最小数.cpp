/*
https://www.nowcoder.com/practice/82e5ff335eeb486aab359767895cc7b4?tpId=40&tqId=21344&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����10024

��Ŀ����
����N����N<=10000�����֣������N�������е����ֵ����Сֵ��ÿ�����ֵľ���ֵ������1000000��
��������:
��������������������ÿ�����������һ������N��ͷ������ȥһ�и���N��������
�������:
�����������������Ϊ����N�����е����ֵ����Сֵ��
ʾ��1
����
5
1 2 3 4 5
3
3 7 8
���
5 1
8 3
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while(cin >> n) {
        int cur;
        int max = -1000001;
        int min = 1000001;
        for (int i = 0; i < n; i++) {
            cin >> cur;
            if (cur > max)
                max = cur;
            if (cur < min)
                min = cur;
        }
        cout << max << " " << min << endl;
    }
}
