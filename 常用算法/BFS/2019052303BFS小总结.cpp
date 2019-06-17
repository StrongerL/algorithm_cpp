/*
bfs经典情况
油田问题，即找到一个图上的联通的地方有几个
迷宫问题，给出起点终点，问到达终点最少移动次数，可能会对步伐设置不同权值，这样的话使用优先队列即可
其他变形，识别状态和每个状态可以做出的选择很关键

bfs常用数据结构
队列存储接下来要访问的节点
数组存储是否访问过 | 也可以用map，map既可以存储访问标识，还可以存储步数
状态：结构体（比较灵活，还可以存储步数） | pair | 哈希映射


*/
#include <iostream>
#include <queue>
using namespace std;

struct State{
    int i;
    int j;
    int step;

    bool operator < (const State& s) {
        return this -> step > s.step;
    }

};


// 问题的最大规模
#define maxn 1001
// 问题的范围
int n;
char f[maxn][maxn];
// 现在和下一个状态
State cur, post;
// 访问标志
int vis[maxn][maxn];
// 每个状态上能做出的选择
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


// 是否已经访问过、是否越界、是否符合其他条件
bool check(State s) {

}

// 广度优先搜索
int bfs(int i, int j) {
    queue<State> q;
    // 每个方向消耗的权重不同时要使用优先队列
    // priority_queue<State> q;
    cur.i = i;
    cur.j = j;
    q.push(cur);

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        // 如果使用问题需要使用优先队列，那么一定要在出队时再设置已访问
        // 如果问题不需要使用优先队列，那么入队时设置已访问也可以
        vis[cur.i][cur.j] = 1;
        for(int i = 0; i < 4; i++) {
            post.i = cur.i + d[i][0];
            post.j = cur.j + d[i][1];
            if (check(post)) {
                // 如果达到目标，返回结果
                if (post.i == 0 && post.j == 0)
                    return post.step;
                q.push(post);
            }
        }
    }

    // 如果遍历完所有可能也没有结果，返回-1或者其他数，表示目标不可达
    return -1;

}


int main() {
    
}

