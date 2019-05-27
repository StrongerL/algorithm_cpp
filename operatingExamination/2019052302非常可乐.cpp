/*
https://vjudge.net/contest/209344#problem/H

H - 非常可乐 HDU - 1495 

大家一定觉的运动以后喝可乐是一件很惬意的事情，但是seeyou却不这么认为。因为每次当seeyou买了可乐以后，阿牛就要求和seeyou一起分享这一瓶可乐，而且一定要喝的和seeyou一样多。但seeyou的手中只有两个杯子，它们的容量分别是N 毫升和M 毫升 可乐的体积为S （S<101）毫升　(正好装满一瓶) ，它们三个之间可以相互倒可乐 (都是没有刻度的，且 S==N+M，101＞S＞0，N＞0，M＞0) 。聪明的ACMER你们说他们能平分吗？如果能请输出倒可乐的最少的次数，如果不能输出"NO"。
Input
三个整数 : S 可乐的体积 , N 和 M是两个杯子的容量，以"0 0 0"结束。
Output
如果能平分的话请输出最少要倒的次数，否则输出"NO"。
Sample Input
7 4 3
4 1 3
0 0 0
Sample Output
NO
3


Time limit      1000 ms
Memory limit    32768 kB
OS              Windows
Source          “2006校园文化活动月”之“校庆杯”大学生程序设计竞赛暨杭州电子科技大学第四届大学生程序设计竞赛


题意：三个杯子装可乐，容积分别S、N、M，S = N + M，开始时S是满的，其他两个杯子是空的，杯子之间可以互倒可乐，
     如果可以将杯子中的可乐平均分为两部分，输出倒的次数，如果不能输出NO。

思路：bfs 或者 数学解法


*/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

int S, N, M;
queue< pair<int, int> > q;
map< pair<int, int>, int> m;
pair<int, int> cur, post;

bool vis(pair<int, int> p) {
    return m.find(p) != m.end();
}

bool bingo(pair<int, int> p) {
    int curN = p.first;
    int curM = p.second;
    int curS = S - curM - curN;

    return curN == curM && curS == 0
        || curN == curS && curM == 0
        || curM == curS && curN == 0;

}

int bfs() {
    cur = make_pair(0, 0);
    m[cur] = 0;
    q.push(cur);
    int curN, curM, curS;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        curN = cur.first;
        curM = cur.second;
        curS = S - curM - curN;

        if (curS > 0) {
            if (curN < N) {
                post.first = curS >= N - curN ? N : curN + curS;
                post.second = curM;
                if (!vis(post)) {
                    if (bingo(post))
                        return m[cur] + 1;
                    m[post] = m[cur] + 1;
                    q.push(post);
                }
            }
            if (curM < M) {
                post.first = curN;
                post.second = curS >= M - curM ? M : curM + curS;
                if (!vis(post)) {
                    if (bingo(post))
                        return m[cur] + 1;
                    m[post] = m[cur] + 1;
                    q.push(post);
                }
            }
        }

        if (curN > 0) {
            if (curS < S) {
                post.first = 0;
                post.second = curM;
                if (!vis(post)) {
                    if (bingo(post))
                        return m[cur] + 1;
                    m[post] = m[cur] + 1;
                    q.push(post);
                }
            }
            if (curM < M) {
                post.first = curN >= M - curM ? curN - (M - curM) : 0;
                post.second = curN >= M - curM ? M : curM + curN; 
                if (!vis(post)) {
                    if (bingo(post))
                        return m[cur] + 1;
                    m[post] = m[cur] + 1;
                    q.push(post);
                }
            }
        }

        if (curM > 0) {
            if (curS < S) {
                post.first = curN;
                post.second = 0;
                if (!vis(post)) {
                    if (bingo(post))
                        return m[cur] + 1;
                    m[post] = m[cur] + 1;
                    q.push(post);
                }
            }
            if (curN < N) {
                post.first = curM >= N - curN ? N : curN + curM;
                post.second = curM >= N - curN ? curM - (N - curN) : 0;
                if (!vis(post)) {
                    if (bingo(post))
                        return m[cur] + 1;
                    m[post] = m[cur] + 1;
                    q.push(post);
                }
            }
        }
    }

    return -1;
}


int main() {
    while (cin >> S >> N >> M && S != 0) {
        m.clear();
        while (!q.empty()) 
            q.pop();
        int res = bfs();
        if (res != -1) 
            cout << res << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}


// // 数学解法
// #include <iostream>
// using namespace std;
// // 辗转相除法求最大公约数
// int gcd(int a, int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

// int main() {
//     int S, N, M;
//     while (cin >> S >> N >> M && S != 0) {
//         S /= gcd(N, M);
//         if (S & 1)
//             cout << "NO" << endl;
//         else
//             cout << S - 1 << endl;
//     }
//     return 0;
// }
