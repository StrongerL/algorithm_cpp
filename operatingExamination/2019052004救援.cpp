/*
https://vjudge.net/contest/209344#problem/F

F - Rescue ZOJ - 1649 

Angel was caught by the MOLIGPY! He was put in prison by Moligpy. The prison is described as a N * M (N, M <= 200) matrix. There are WALLs, ROADs, and GUARDs in the prison.

Angel's friends want to save Angel. Their task is: approach Angel. We assume that "approach Angel" is to get to the position where Angel stays. When there's a guard in the grid, we must kill him (or her?) to move into the grid. We assume that we moving up, down, right, left takes us 1 unit time, and killing a guard takes 1 unit time, too. And we are strong enough to kill all the guards.

You have to calculate the minimal time to approach Angel. (We can move only UP, DOWN, LEFT and RIGHT, to the neighbor grid within bound, of course.)


Input
First line contains two integers stand for N and M.

Then N lines follows, every line has M characters. "." stands for road, "a" stands for Angel, and "r" stands for each of Angel's friend.

Process to the end of the file.



Output
For each test case, your program should output a single integer, standing for the minimal time needed. If such a number does no exist, you should output a line containing "Poor ANGEL has to stay in the prison all his life."

Sample Input
7 8 
#.#####. 
#.a#..r. 
#..#x... 
..#..#.# 
#...##.. 
.#...... 
........

Sample Output
13


Time limit      2000 ms
Memory limit    65536 kB
OS              Linux
Source          ZOJ Monthly, October 2003AuthorCHEN, Xue

题意：r是营救人员，a是需要被营救的天使，.是路，#是墙，x是守卫，
    r需要营救a，墙不能走，.需要消耗1个单位时间，x需要消耗2个单位
    时间（走一步 + 杀死守卫），求营救天使所需最短时间，如果不能营救
    输出一段要求的字符串。

思路：bfs + 优先队列

*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class State {
    public:
        int i;
        int j;
        int t;

        bool operator < (const State& s) const{
            return this -> t > s.t;
        }

        State(){}

        State(int i, int j, int t){
            this -> i = i;
            this -> j = j;
            this -> t = t;
        }
};

int n, m;
char f[202][202];
int vis[202][202];
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


bool validate(State s) {
    return s.i >= 0 && s.i < n && s.j >= 0 && s.j < m && 
            f[s.i][s.j] != '#' && !vis[s.i][s.j];
}

int bfs(int i, int j) { 
    State cur, next;
    priority_queue<State> q;
    cur = State(i, j, 0);
    q.push(cur);
    while (!q.empty()) {
        cur = q.top();
        q.pop();
        vis[cur.i][cur.j] = 1;

        for (int i = 0; i < 4; i++) {
            next.i = cur.i + d[i][0];
            next.j = cur.j + d[i][1];
            // 忘记加!vis[next.i][next.j]导致空间溢出，找了1个多小时。。。
            // 以后直接在validate函数中判断是否访问吧
            if (validate(next)) {
                vis[next.i][next.j] = 1;
                next.t = cur.t + 1;
                char ch = f[next.i][next.j];
                if (ch == 'a')
                    return cur.t + 1;                         
                if (ch == 'x')
                    next.t++;
                q.push(next);
            }
        }

    }
    return -1;
}


int main() {
    while (cin >> n >> m) {
        memset(vis, 0, sizeof(vis));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> f[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (f[i][j] == 'r') {
                    int res = bfs(i, j);
                    if (res != -1)
                        cout << res << endl;
                    else
                        cout << "Poor ANGEL has to stay in the prison all his life." << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
