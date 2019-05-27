/*
https://vjudge.net/contest/209344#problem/A

A - Oil Deposits ZOJ - 1709 

The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits. GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to determine whether or not the plot contains oil. A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to determine how many different oil deposits are contained in a grid.

Input

The input file contains one or more grids. Each grid begins with a line containing m and n, the number of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100. Following this are m lines of n characters each (not counting the end-of-line characters). Each character corresponds to one plot, and is either `*', representing the absence of oil, or `@', representing an oil pocket.


Output

For each grid, output the number of distinct oil deposits. Two different pockets are part of the same oil deposit if they are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain more than 100 pockets.


Sample Input

1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5 
****@
*@@*@
*@**@
@@@*@
@@**@
0 0


Sample Output

0
1
2
2

Time limit      2000 ms
Memory limit    65536 kB
OS              Linux
Source          Mid-Central USA 1997

题意：求油田数目

思路：典型的bfs

*/


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 油田大小
int m, n;
// 记录该位置是否已经访问
int vis[100][100];
// 油田
char oil[100][100];
// 8个方向
int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                {0, -1},          {0, 1},
                {1, -1}, {1, 0},  {1, 1}};

// 验证位置是否越界
bool validate(int i, int j) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

// 以油田i行j列开始向四周探索油田
void bfs(int i, int j) {
    vis[i][j] = 1;
    queue< pair<int, int> > q;
    q.push(make_pair(i, j));
    pair<int, int> p;

    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = p.first + d[i][0];
            int y = p.second + d[i][1];
            if (validate(x, y) && !vis[x][y]) {
                vis[x][y] = 1;
                // 如果该位置也是油田，加入队列继续探索
                if (oil[x][y] == '@') {
                    q.push(make_pair(x, y));
                }
            }

        }
    }


}


int main() {
    while (cin >> m >> n && m != 0) {
        // 初始化
        memset(vis, 0, sizeof(vis));       
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> oil[i][j];
            }
        } 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && oil[i][j] == '@') {
                    bfs(i, j);
                    count++;
                }
                // 已访问
                vis[i][j] = 1;
            }
        }
        cout << count << endl;
    }
}


