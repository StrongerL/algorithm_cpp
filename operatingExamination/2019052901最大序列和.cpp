/*
https://www.nowcoder.com/practice/df219d60a7af4171a981ef56bd597f7b?tpId=40&tqId=21353&tPage=2&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

������к�

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����7381

��Ŀ����
����һ����������S��������N��������������һ���ǿ�����������T���������ĺ�ΪT�ġ����к͡��� ����S�����зǿ�����������T�����������к͡� ����������NΪ��������N��1000000��������к��ڷ�Χ��-2^63,2^63-1�����ڡ�
��������:
��һ��Ϊһ��������N���ڶ���ΪN����������ʾ�����е�����
�������:
������ܰ����������ݣ�����ÿһ���������ݣ�
�����һ��������ʾ������к͡�
ʾ��1
����
5
1 5 -3 2 4

6
1 -2 3 4 -10 6

4
-3 -1 -2 -5
���
9
7
-1

˼·�������ۼӲ��ڵ�ǰ���ͱȽϣ������ǰ�ĺ�Ϊ������������Ϊ0

*/

#include <iostream>
using namespace std;
long long num[1000010];
int N;
int main() {
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
        long long maxSum = num[0];
        long long curSum = 0;
        for (int i = 0; i < N; i++) {
            curSum += num[i];
            if (curSum > maxSum)
                maxSum = curSum;
            if (curSum <= 0)
                curSum = 0;
        }
        cout << maxSum << endl;
    }
}
