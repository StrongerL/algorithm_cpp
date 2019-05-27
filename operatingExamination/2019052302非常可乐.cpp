/*
https://vjudge.net/contest/209344#problem/H

H - �ǳ����� HDU - 1495 

���һ�������˶��Ժ�ȿ�����һ�����������飬����seeyouȴ����ô��Ϊ����Ϊÿ�ε�seeyou���˿����Ժ󣬰�ţ��Ҫ���seeyouһ�������һƿ���֣�����һ��Ҫ�ȵĺ�seeyouһ���ࡣ��seeyou������ֻ���������ӣ����ǵ������ֱ���N ������M ���� ���ֵ����ΪS ��S<101��������(����װ��һƿ) ����������֮������໥������ (����û�п̶ȵģ��� S==N+M��101��S��0��N��0��M��0) ��������ACMER����˵������ƽ�������������������ֵ����ٵĴ���������������"NO"��
Input
�������� : S ���ֵ���� , N �� M���������ӵ���������"0 0 0"������
Output
�����ƽ�ֵĻ����������Ҫ���Ĵ������������"NO"��
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
Source          ��2006У԰�Ļ���¡�֮��У�챭����ѧ��������ƾ����ߺ��ݵ��ӿƼ���ѧ���Ľ��ѧ��������ƾ���


���⣺��������װ���֣��ݻ��ֱ�S��N��M��S = N + M����ʼʱS�����ģ��������������ǿյģ�����֮����Ի������֣�
     ������Խ������еĿ���ƽ����Ϊ�����֣�������Ĵ���������������NO��

˼·��bfs ���� ��ѧ�ⷨ


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


// // ��ѧ�ⷨ
// #include <iostream>
// using namespace std;
// // շת����������Լ��
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
