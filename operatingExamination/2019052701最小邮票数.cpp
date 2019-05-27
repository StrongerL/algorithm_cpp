/*
https://www.nowcoder.com/practice/83800ae3292b4256b7349ded5f178dd1?tpId=40&tqId=21345&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

��С��Ʊ��

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����8965

��Ŀ����
    ����������Ʊ��Ҫ�����ѡȡ���ٵ���Ʊ�����ճ�һ����������ֵ��     �磬��1�֣�3�֣�3�֣�3�֣�4��������Ʊ��Ҫ��ճ�10�֣���ʹ��3����Ʊ��3�֡�3�֡�4�ּ��ɡ�
��������:
    �ж������ݣ�����ÿ�����ݣ�������Ҫ��ճɵ���Ʊ��ֵM��M<100��Ȼ����һ����N��N��20����ʾ��N����Ʊ����������N�����������ֱ��ʾ��N����Ʊ����ֵ�������������С�
�������:
      ����ÿ�����ݣ��ܹ��ճ���ֵM��������Ʊ���������޽⣬���0��
ʾ��1
����
10
5
1 3 3 3 4
���
3


˼·��0-1�����򻯰棬dp[]����洢������������С��Ʊ�������޷������ֵΪINF

*/

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 20
int dp[101];
int stamp[21];
int M, N;

int main() {
    while (cin >> M >> N) {
        // ����
        for (int i = 1; i <= N; i++) {
            cin >> stamp[i];
        }
        // �߽�����
        dp[0] = 0;
        for(int j = 1; j <= M; j++) {
            dp[j] = (stamp[1] == j) ? 1 : INF;
        }
        // ״̬ת��
        for (int i = 2; i <= N; i++) {
            for (int j = M; j >= stamp[i]; j--) {
                // min()����ͷ�ļ�<algorithm>
                dp[j] = min(dp[j], dp[j - stamp[i]] + 1);
            }
        }
        // ���
        if (dp[M] == INF)
            cout << 0 << endl;
        else
            cout << dp[M] << endl;
    }
}
