/*
https://www.nowcoder.com/practice/1f1db273eeb745c6ac83e91ff14d2ec9?tpId=40&tqId=21366&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tPage=2

��������

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����4417

��Ŀ����
����n������������ȡ�������ֱ���Ϊ���Ӻͷ�ĸ�������������������м�����������ϡ�
��������:
ÿ�����n��n<=600����n����ͬ����������������1��С�ڵ���1000��
�������:
ÿ���������������ϵĸ�����
ʾ��1
����
7
3 5 7 9 11 13 15
���
17



 */

#include <iostream>
using namespace std;

int nums[610];

bool check(int a, int b) {
    int large, small;
    if (a >= b) {
        large = a;
        small = b;
    } else {
        large = b;
        small = a;
    }
    for (int i = 2; i <= small; i++) {
        if (small % i == 0 && large % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(nums[i], nums[j]))
                    count++;
            }
        }
        
        cout << count << endl;
    }
}
