/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856


题目
1021 Deepest Root (25分)


思路
https://www.liuchuo.net/archives/2348
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, max_depth;
int g[10010][10010];
int vis[10010];
vector<int> tmp;

void dfs(int root, int depth) {
    vis[root] = 1;
    if (depth > max_depth) {
        tmp.clear();
        tmp.push_back(root);
        max_depth = depth;
    } else if(depth == max_depth) {
        tmp.push_back(root);
    }
    for (int i = 1; i <= n; i++) {
        if(!vis[i] && g[root][i]) {
            dfs(i, depth + 1);
        }
    }
}

int main() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 1);
            components++;
        }
    }
    if (components == 1) {
        set<int> ans(tmp.begin(), tmp.end());
        fill(vis + 1, vis + 1 + n, 0);
        tmp.clear();
        dfs(*ans.begin(), 1);
        for (int i = 0; i < tmp.size(); i++) {
            ans.insert(tmp[i]);
        }
        for (auto it = ans.begin(); it != ans.end(); it++) {
            cout << *it << endl;
        }
        
    } else {
        cout << "Error: " << components << " components";
    }
}
