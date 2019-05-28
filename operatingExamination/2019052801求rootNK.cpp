/*
https://www.nowcoder.com/practice/9324a1458c564c4b9c4bfc3867a2aa66?tpId=40&tqId=21347&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

��root(N, K)

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����5441

��Ŀ����
    N<kʱ��root(N,k) = N������root(N,k) = root(N',k)��N'ΪN��k���Ʊ�ʾ�ĸ�λ����֮�͡�����x,y,k�����root(x^y,k)��ֵ (����^Ϊ�˷����������)��2=<k<=16��0<x,y<2000000000����һ��Ĳ��Ե��� x^y �����int�ķ�Χ(>=2000000000) 
��������:
    ÿ��������ݰ���һ�У�x(0<x<2000000000), y(0<y<2000000000), k(2<=k<=16)
�������:
    ��������ж������ݣ�����ÿһ�����ݣ�root(x^y, k)��ֵ
ʾ��1
����
4 4 10
���
4


����һ�ֽⷨ
https://blog.csdn.net/merlini_/article/details/50651349

*/

#include <iostream>
using namespace std;

int x, y, k;

// root(x, y, k) = x ^ y % (k - 1) ���� k - 1��Ȼ����������
int r(int x, int y, int k) {
    k--;
    int res = 1;
    x = x % k;
    while (y) {
        if (y & 1)
            res = res * x % k;
        x = x * x % k;
        y >>= 1;
    }
    return res;
}

int main() {
    while (cin >> x >> y >> k) {
        int res = r(x, y, k);
        if (res == 0)
            cout << k - 1 << endl;
        else
            cout << res << endl;
    }
}
