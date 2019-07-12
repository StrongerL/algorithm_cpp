/*
https://acm.ecnu.edu.cn/contest/186/problem/F/#report4

F. 小啵的抽奖
单点时限: 1.0 sec

内存限制: 512 MB

小啵邀请了 N (1≤N≤20) 位同学来参加他的抽奖活动。

每位同学都有一个抽奖券，他们只需要在抽奖券上写下自己的名字，然后扔进抽奖箱中。

接着，小啵会随机给每位同学发 一个 抽奖券，如果一位同学拿到了写有自己名字的抽奖券，那么他就中奖了。

小啵的问题是，他有多大的概率不用准备任何奖品？（也就是说，没有任何人中奖）

答案以百分比形式给出，保留到小数点后两位。

输入格式
第一行输入一个整数 Q ，表示有 Q 轮抽奖。

接下来 Q 行，每行输入一个整数 N ，表示这一轮抽奖的人数。

输出格式
输出 Q 行，每行一个百分比数，表示没有人中奖的概率。

样例
input
2
2
3
output
50.00%
33.33%
提示
如果有两个人参加抽奖，那么只有两种情况：要么全部中奖，要么全部不中奖，答案为 12=50.00% 。

数据范围：

50% 的数据满足：1≤N≤10

100% 的数据满足：1≤N,Q≤20


思路：
    分母为 A(n, n)
    分子为 a(n) = (n - 1) * (a(n - 1) + a(n - 2));
    例如 1 2 3 4
    如果1可以放在2、3或者4的位置3种, 即 n - 1 种位置
    以1放在2的位置为例，2放置的位置有两种可能：
    放在1的位置，种类数为a(n - 2)
    不放在1的位置，可以将1的位置视为2的位置，这样的话种类数为a(n - 1)
    综上，分子为 a(n) = (n - 1) * (a(n - 1) + a(n - 2));
    
 */



#include <iostream>
#include <iomanip>
using namespace std;

// 分子
long long permutation(int n) {

    if (n == 1)
        return 0;
    if (n == 2) 
        return 1;

    return (n - 1) * (permutation(n - 1) + permutation(n - 2));

}

// 分母
long long ann(int n) {
    long long ans = 1;
    for (int i = n; i > 1; i--) {
        ans *= i;
    }
    return ans;
}

int main()
{
    double ans, n;
    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        // 分母
        long long denominator = ann(n);
        // 分子
        long long numerator = permutation(n);
        ans = 1.0 * numerator / denominator * 100;
        cout << fixed << setprecision(2) << ans << "%" << endl;
    }


}
