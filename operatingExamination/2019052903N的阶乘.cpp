/*
https://www.nowcoder.com/practice/f54d8e6de61e4efb8cce3eebfd0e0daa?tpId=40&tqId=21355&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tPage=2

N�Ľ׳�

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����8090

��Ŀ����
 ����һ��������N�����N�Ľ׳ˡ�
��������:
������N(0<=N<=1000)
�������:
 ������ܰ����������ݣ�����ÿһ���������ݣ����N�Ľ׳�
ʾ��1
����
4
5
15
���
24
120
1307674368000


˼·�������׳�
�ο���ַ��https://blog.csdn.net/lisp1995/article/details/52403507#commentBox

*/

#include <iostream>
using namespace std;
int num[3000];
// place��λ����carry�ǽ�λ
int n, place, tmp, carry;
int main() {
    while (cin >> n) {
        // ��ʼʱλ��Ϊ1����ʼֵΪ1����λΪ0
        place = 1;
        num[0] = 1;
        carry = 0;
        // ��2��ʼ����׳�
        for (int i = 2; i <= n; i++) {
            // ��ǰ����ÿһλ�ֱ���i���
            for (int j = 0; j < place; j++) {
                tmp = num[j] * i + carry;
                num[j] = tmp % 10;
                carry = tmp / 10;
            }
            // ��������껹�н�λ
            while (carry) {
                num[place++] = carry % 10;
                carry /= 10;
            }
        }
        // �������
        for (int i = place - 1; i >= 0; i--) {
            cout << num[i];
        }
    }
}
