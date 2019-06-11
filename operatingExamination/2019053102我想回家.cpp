/*

https://www.nowcoder.com/practice/0160bab3ce5d4ae0bb99dc605601e971?tpId=40&tqId=21359&tPage=2&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

I Wanna Go Home


时间限制：1秒 空间限制：65536K 热度指数：3090

题目描述
    The country is facing a terrible civil war----cities in the country are divided into two parts supporting different leaders. As a merchant, Mr. M does not pay attention to politics but he actually knows the severe situation, and your task is to help him reach home as soon as possible.     "For the sake of safety,", said Mr.M, "your route should contain at most 1 road which connects two cities of different camp."     Would you please tell Mr. M at least how long will it take to reach his sweet home?
输入描述:
    The input contains multiple test cases.
    The first line of each case is an integer N (2<=N<=600), representing the number of cities in the country.
    The second line contains one integer M (0<=M<=10000), which is the number of roads.
    The following M lines are the information of the roads. Each line contains three integers A, B and T, which means the road between city A and city B will cost time T. T is in the range of [1,500].
    Next part contains N integers, which are either 1 or 2. The i-th integer shows the supporting leader of city i. 

    To simplify the problem, we assume that Mr. M starts from city 1 and his target is city 2. City 1 always supports leader 1 while city 2 is at the same side of leader 2. 
    Note that all roads are bidirectional and there is at most 1 road between two cities.
    Input is ended with a case of N=0.
输出描述:
    For each test case, output one integer representing the minimum time to reach home.
    If it is impossible to reach home according to Mr. M's demands, output -1 instead.
示例1
输入
2
1
1 2 100
1 2
3
3
1 2 100
1 3 40
2 3 50
1 2 1
5
5
3 1 200
5 3 150
2 5 160
4 3 170
4 2 170
1 2 2 2 1
0
输出
100
90
540

题意：第一行输入城市个数
     第二行输入路径个数
     之后输入路径，格式为城市1 城市2 消耗时间（题目说城市之间路径只有一条，但是用例其实有多条）
     输入每个城市所属阵营
     城市个数为0时输入结束

     要求从城市1到城市2，城市1属于阵营1，城市2属于阵营2，路径只能从1到2变一次
     输出最短时间，如果不能到达，输出-1


思路：bfs + 优先队列，注意访问置为1的代码位置

*/

#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

class State{
    public:
        int pos;
        int time;
        bool campChanged;
        
        bool operator < (const State& s) const{
            return (this -> time) > s.time;
        }
};

int dis[610][610];
int vis[610];
int camp[610];
int N, M;
priority_queue<State> q;
State cur, post;

bool check(State s, int toPos) {
    if (camp[s.pos] != camp[toPos] && s.campChanged)
        return false;
    return !vis[toPos] && dis[s.pos][toPos];
}

int bfs() {
    cur.time = 0;
    cur.campChanged = false;
    cur.pos = 1;
    q.push(cur);

    while(!q.empty()) {
        cur = q.top();
        q.pop();
        if (vis[cur.pos]) 
            continue;
        // 状态弹出之后再将访问置为1，之前一直弄错，找出这个错误用了一晚上
        vis[cur.pos] = 1;
        if (cur.pos == 2)
            return cur.time;
        for (int i = 1; i <= N; i++) {
            if (check(cur, i)) {
                post.pos = i;
                post.time = cur.time + dis[cur.pos][i];
                post.campChanged = cur.campChanged;
                if (camp[cur.pos] != camp[i]) {
                    post.campChanged = true;
                }
                q.push(post);
            }
        }
    }

    return -1;
}

int main() {
    while (cin >> N && N) {
        cin >> M;
        while (!q.empty())  q.pop();
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        int j, k, t;
        for (int i = 0; i < M; i++) {
            cin >> j >> k >> t;
            if (t < dis[j][k] || dis[j][k] == 0) {
                dis[j][k] = t;
                dis[k][j] = t;
            }
        }
        for (int i = 1; i <= N; i++) {
            cin >> camp[i];
        }
        cout << bfs() << endl;
    }
}
