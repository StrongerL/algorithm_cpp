/*
https://www.nowcoder.com/practice/2364ff2463984f09904170cf6f67f69a?tpId=40&tqId=21367&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

��λ��

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����5228

��Ŀ����
��λ�����壺һ�����ݰ���С�����˳���������У������м�λ�õ�һ�����������м��������ݵ�ƽ������. ����һ�����������������λ������������м���������ƽ����������ȡ�����ɣ�����Ҫʹ�ø�������
��������:
�ó����������������ݣ�ÿһ��������ݵĵ�һ��ΪN���������������ݰ��������ݸ�����1<=N<=10000.
����N��ΪN�����ݵ����룬N=0ʱ��������
�������:
�����λ����ÿһ������������һ��
ʾ��1
����
4
10
30
20
40
3
40
30
50
4
1
2
3
4
0
���
25
40
2

 */

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int nums[10010];

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums, nums + n);
        if (n & 1) {
            cout << nums[n / 2] << endl;
        } else {
            cout << (nums[n / 2 - 1] + nums[n / 2]) / 2 << endl;
        }
        
    }
}
