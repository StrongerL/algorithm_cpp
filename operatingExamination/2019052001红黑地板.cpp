/*
https://vjudge.net/contest/209344#problem/C

C - Red and Black HDU - 1312 

There is a rectangular room, covered with square tiles. Each tile is colored either red or black. A man is standing on a black tile. From a tile, he can move to one of four adjacent tiles. But he can't move on red tiles, he can move only on black tiles. 

Write a program to count the number of black tiles which he can reach by repeating the moves described above. 
Input
The input consists of multiple data sets. A data set starts with a line containing two positive integers W and H; W and H are the numbers of tiles in the x- and y- directions, respectively. W and H are not more than 20. 

There are H more lines in the data set, each of which includes W characters. Each character represents the color of a tile as follows. 

'.' - a black tile 
'#' - a red tile 
'@' - a man on a black tile(appears exactly once in a data set) 
Output
For each data set, your program should output a line which contains the number of tiles he can reach from the initial tile (including itself). 
Sample Input
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
Sample Output
45
59
6
13


Time limit  1000 ms
Memory      limit32768 kB
OS          Windows
Source      Asia 2004, Ehime (Japan), Japan Domestic

题意：@为起点，.为黑色地板，#为红色地板，可以踩黑色地板，不能踩红色地板，
     求能到达的黑色地板的个数（包括起点）。

思路：bfs

*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
// res换成count会提示变量不明确编译不通过。。。。为什么呢
int res;
char f[21][21];
int vis[21][21];
int d[][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool validate(int i, int j) {
    return i < h && i >= 0 && j < w && j >= 0 && f[i][j] == '.';
}

void bfs(int i, int j) {

    queue< pair<int, int> > q;
    pair<int, int> p;
    vis[i][j] = 1;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = p.first + d[i][0];
            int y = p.second + d[i][1];
            if (validate(x, y) && !vis[x][y]) {
                vis[x][y] = 1;
                res++;
                q.push(make_pair(x, y));
            }
        }
    }

}

int main() {
    while (cin >> w >> h && w * h != 0) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> f[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (f[i][j] == '@') {
                    vis[i][j] = 1;
                    res = 1;
                    bfs(i, j);
                    break;
                }
            }
        }

        cout << res << endl;
    }
}
