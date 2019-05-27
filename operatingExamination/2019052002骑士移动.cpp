/*
https://vjudge.net/contest/209344#problem/D

D - Knight Moves POJ - 1915 

Background 
Mr Somurolov, fabulous chess-gamer indeed, asserts that no one else but him can move knights from one position to another so fast. Can you beat him? 
The Problem 
Your task is to write a program to calculate the minimum number of moves needed for a knight to reach one point from another, so that you have the chance to be faster than Somurolov. 
For people not familiar with chess, the possible knight moves are shown in Figure 1.

同中国象棋中马的走法

Input
The input begins with the number n of scenarios on a single line by itself. 
Next follow n scenarios. Each scenario consists of three lines containing integer numbers. The first line specifies the length l of a side of the chess board (4 <= l <= 300). The entire board has size l * l. The second and third line contain pair of integers {0, ..., l-1}*{0, ..., l-1} specifying the starting and ending position of the knight on the board. The integers are separated by a single blank. You can assume that the positions are valid positions on the chess board of that scenario.
Output
For each scenario of the input you have to calculate the minimal amount of knight moves which are necessary to move from the starting point to the ending point. If starting point and ending point are equal,distance is zero. The distance must be written on a single line.
Sample Input
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
Sample Output
5
28
0


Time limit      1000 ms
Memory limit    30000 kB
OS              Linux
Source          TUD Programming Contest 2001, Darmstadt, Germany

题意：给出骑士（走法同中国象棋的马）的起点和终点，求最小移动次数

思路：bfs

*/


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class State {
    public:
        int i;
        int j;
        int step;

        State(){}

        State(int i, int j, int step) {
            this -> i = i;
            this -> j = j;
            this -> step = step;
        }

        bool operator==(const State& s){
            return this -> i == s.i && this -> j == s.j;
        }
};

int n;
int vis[301][301];
int d[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
               {1, -2}, {2, -1}, {2, 1}, {1, 2}}; 

// post写成next会报错
State cur, post, target;
queue<State> q;

bool validate(State s) {
    return s.i >= 0 && s.i < n && s.j >= 0 && s.j <n;
}


int bfs() {
    if (cur == target)
        return 0;
    q.push(cur);
    vis[cur.i][cur.j] = 1;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            post.i = cur.i + d[i][0];
            post.j = cur.j + d[i][1];          
            if (validate(post) && !vis[post.i][post.j]) {
                vis[post.i][post.j] = 1;
                post.step = cur.step + 1;
                if (post == target) {
                    return post.step;
                } else {
                    q.push(post);
                }
            }
            
        }
    }
    return -1;
}


int main() {

    int m;
    int i1, j1, i2, j2;
    cin >> m;
    while (m--) {
        cin >> n;
        cin >> i1 >> j1 >> i2 >> j2;
        cur = State(i1, j1, 0);
        target = State(i2, j2, 0);
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
            q.pop();
        int res = bfs();
        cout << res << endl;
    }
    return 0;
}



/*

该代码会tle，为什么呢？

#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int n;
pair<int, int> target;
int vis[301][301];
int d[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
               {1, -2}, {2, -1}, {2, 1}, {1, 2}}; 

map<pair<int, int>, int> m;
queue< pair<int, int> > q;

bool validate(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int bfs(int i, int j) {
    vis[i][j] = 1;
    pair<int, int> p = make_pair(i, j);
    q.push(p);
    m[p] = 0;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int ii = p.first + d[i][0];
            int jj = p.second + d[i][1];
            if (validate(ii, jj) && !vis[ii][jj]) {
                vis[ii][jj] = 1;
                pair<int, int> tmp = make_pair(ii, jj);
                if (tmp == target) 
                    return m[p] + 1;
                else {
                    q.push(tmp);
                    m[tmp] = m[p] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    int t;
    int i1, j1, i2, j2;
    cin >> t;
    while (t > 0) {

        m.clear();
        while (!q.empty()) 
            q.pop();
        memset(vis, 0, sizeof(vis));

        cin >> n;
        cin >> i1 >> j1 >> i2 >> j2;
        
        if (i1 == i2 && j1 == j2) {
            cout << 0 << endl;
            t--;
            continue;
        }
        
        target = make_pair(i2, j2);
        int res = bfs(i1, j1);
        cout << res << endl;

        t--;
    }

    
}
*/
