/*
https://www.nowcoder.com/practice/e6df3e3005e34e2598b9b565cfe797c9?tpId=40&tqId=21354&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

��С����

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����3456

��Ŀ����
��ĳ����·����N����վ�������־����·�̣�L1��L2��L3,��Ӧ�ļ۸�ΪC1,C2,C3.���Ӧ��ϵ����: 
����s           Ʊ�� 
0<S<=L1         C1 
L1<S<=L2        C2 
L2<S<=L3        C3 
���뱣֤0<L1<L2<L3<10^9,0<C1<C2<C3<10^9�� ÿ����վ֮��ľ��벻����L3�� ���˿�Ҫ�ƶ�������վ�ľ������L3��ʱ�򣬿���ѡ����м�һ��վ�³���Ȼ����Ʊ���ϳ������Գ˿��������������ٻ�������Ʊ�� ���ڸ���һ�� L1��L2��L3��C1��C2,C3��Ȼ����A B��ֵ����ֱ�Ϊ�˿��ó̵���ʼվ���յ�վ�� Ȼ������N��NΪ����·�ϵ��ܵĻ�վ��Ŀ��Ȼ������N-1���������ֱ����Ӹ���·�ϵĵ�һ��վ������2��վ����3��վ����������N��վ�ľ��롣 �������룬����˿ʹ�A��Bվ����С���ѡ�
��������:
�����¸�ʽ�������ݣ�
L1  L2  L3  C1  C2  C3
A  B
N
a[2]
a[3]
����
a[N]
�������:
�����ж���������ݣ�����ÿһ�����ݣ�
�������룬����˿ʹ�A��Bվ����С���ѡ�
ʾ��1
����
1 2 3 1 2 3
1 2
2
2
���
2

˼·����̬�滮��ÿ����վҪô��ǰһ����վ��Ʊ��Ҫôǰǰһ����վ��Ʊ��Ҫô��...��ֱ��������볬�� L3��

*/


#include <iostream>
#include <climits>
using namespace std;
int L1, L2, L3, C1, C2, C3, A, B, N;

// ���ݾ����ȡ�۸�
int getPrice(int S) {
    if (S <= L1)
        return C1;
    if (S <= L2)
        return C2;
    return C3;
}

int main() {
    while (cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3 >> A >> B >> N) {
        // ����
        int dis[N + 1];
        int cost[N + 1];
        dis[1] = 0;
        for (int i = 2; i <= N; i++) {
            cin >> dis[i];
        }

        // ����
        cost[A] = 0;
        for (int i = A + 1; i <= B; i++) {
            cost[i] = INT_MAX;
            for (int j = i - 1; j >= A; j--) {
                int s = dis[i] - dis[j];
                if (s <= L3) {
                    int c = cost[j] + getPrice(s);
                    if (cost[i] > c)
                        cost[i] = c;
                } else {
                    break;
                }
            }
        }
        
        // ���
        cout << cost[B] << endl;
    }
}
