/*
С�����Ŷ�

https://www.nowcoder.com/practice/27fbaa6c7b2e419bbf4de8ba60cf372b?tpId=40&tqId=21368&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����4032

��Ŀ����
NֻС����(1 <= N <= 100)��ÿֻ��ͷ�ϴ���һ������ɫ��ñ�ӡ����ڳƳ�ÿֻ�����������Ҫ���հ��������Ӵ�С��˳���������ͷ��ñ�ӵ���ɫ��ñ�ӵ���ɫ�á�red������blue�����ַ�������ʾ����ͬ��С������Դ���ͬ��ɫ��ñ�ӡ������������������ʾ��
��������:
�స�����룬ÿ�������������һ��Ϊһ������N����ʾС�������Ŀ��
������N�У�ÿ����һֻ�������Ϣ����һ��Ϊ������100������������ʾ��������������ڶ���Ϊ�ַ�������ʾ�����ñ����ɫ���ַ������Ȳ�����10���ַ���

ע�⣺���������������ͬ��
�������:
ÿ���������հ���������Ӵ�С��˳����������ñ����ɫ��
ʾ��1
����
3
30 red
50 blue
40 green
���
blue
green
red

 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Mouse{
    int weight;
    string color;
    
    bool operator < (const Mouse& m) const {
        return weight > m.weight;
    } 
};

Mouse ms[110];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> ms[i].weight >> ms[i].color;
        }
        sort(ms, ms + n);
        for (int i = 0; i < n; i++) {
            cout << ms[i].color << endl;
        }
    }
}

