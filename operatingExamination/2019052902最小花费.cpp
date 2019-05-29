/*
https://www.nowcoder.com/practice/e6df3e3005e34e2598b9b565cfe797c9?tpId=40&tqId=21354&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

最小花费

时间限制：1秒 空间限制：65536K 热度指数：3456

题目描述
在某条线路上有N个火车站，有三种距离的路程，L1，L2，L3,对应的价格为C1,C2,C3.其对应关系如下: 
距离s           票价 
0<S<=L1         C1 
L1<S<=L2        C2 
L2<S<=L3        C3 
输入保证0<L1<L2<L3<10^9,0<C1<C2<C3<10^9。 每两个站之间的距离不超过L3。 当乘客要移动的两个站的距离大于L3的时候，可以选择从中间一个站下车，然后买票再上车，所以乘客整个过程中至少会买两张票。 现在给你一个 L1，L2，L3，C1，C2,C3。然后是A B的值，其分别为乘客旅程的起始站和终点站。 然后输入N，N为该线路上的总的火车站数目，然后输入N-1个整数，分别代表从该线路上的第一个站，到第2个站，第3个站，……，第N个站的距离。 根据输入，输出乘客从A到B站的最小花费。
输入描述:
以如下格式输入数据：
L1  L2  L3  C1  C2  C3
A  B
N
a[2]
a[3]
……
a[N]
输出描述:
可能有多组测试数据，对于每一组数据，
根据输入，输出乘客从A到B站的最小花费。
示例1
输入
1 2 3 1 2 3
1 2
2
2
输出
2

思路：动态规划，每个车站要么从前一个车站买票，要么前前一个车站买票，要么从...，直到这个距离超过 L3。

*/


#include <iostream>
#include <climits>
using namespace std;
int L1, L2, L3, C1, C2, C3, A, B, N;

// 根据距离获取价格
int getPrice(int S) {
    if (S <= L1)
        return C1;
    if (S <= L2)
        return C2;
    return C3;
}

int main() {
    while (cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3 >> A >> B >> N) {
        // 输入
        int dis[N + 1];
        int cost[N + 1];
        dis[1] = 0;
        for (int i = 2; i <= N; i++) {
            cin >> dis[i];
        }

        // 动规
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
        
        // 输出
        cout << cost[B] << endl;
    }
}
