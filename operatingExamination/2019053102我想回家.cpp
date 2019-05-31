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
    vis[1] = 1;
    cur.time = 0;
    cur.campChanged = false;
    cur.pos = 1;
    q.push(cur);
    for (int i = 2; i <= N; i++) {
        if (dis[1][i]) {
            vis[i] = 1;
            post.pos = i;
            post.time = dis[1][i];
            if (camp[1] != camp[i])
                post.campChanged = true;
            q.push(post);
        }
    }
    vis[2] = 0;

    while(!q.empty()) {
        cur = q.top();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (check(cur, i)) {
                if (i == 2) 
                    return cur.time + dis[cur.pos][i];
                vis[i] = 1;
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
        while (!q.empty()) 
            q.pop();
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        int j, k, t;
        for (int i = 0; i < M; i++) {
            cin >> j >> k;
            cin >> t;
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
