/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840


题目
1013 Battle Over Cities (25分)


思路
dfs
*/

#include <iostream>
using namespace std;
int n, m, k;
int matrix[1010][1010];
int vis[1010];

void dfs(int cur) {
    vis[cur] = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && matrix[cur][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    int x, y, cur;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    for (int i = 0; i < k; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            vis[j] = 0;
        }
        cin >> cur;
        vis[cur] = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                cnt++;
                dfs(j);
            }
        }
        cout << (cnt - 1) << endl;
    }
}
