/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376


题目
1003 Emergency (25分)


思路
*/


#include <iostream>
#include <cmath>
#include <stdio.h>
#include <climits>
#include <string.h>

using namespace std;

const int N = 501;

int city[N];
int matrix[N][N];
bool visit[N];

int n, m, st, ed, c1, c2, l;
int sc = 0, mc = 0;
long long minl = LLONG_MAX;

//length:到当前城市(编号cid)的距
//mans:到当前城市能够gather到的team数 
//cid:当前城市编号
void dfs(int length, int mans, int cid)
{
    //找到目的地要更新计数
    if (cid == ed)
    {
        if (length > minl)return;
        if (length < minl)
        {
            sc = 1;
            minl = length;
            mc = mans;
        }
        else
        {
            ++sc;
            if (mc < mans)mc = mans;
        }
        return;
    }

    //剪枝，如果距离大于最小距离，这条路将不用继续走下去了
    if (length > minl)return;
    for (int i = 0; i < n; ++i)
    {
        if (matrix[cid][i] == -1 || visit[i])continue;
        visit[i] = true;
        dfs(length + matrix[cid][i], mans + city[i], i);
        visit[i] = false;
    }
}

int main()
{
    //-1表示i和j表示的城市之间无通路
    memset(matrix, -1, sizeof(matrix));
    memset(visit, 0, sizeof(visit));
    cin >> n >> m >> st >> ed;
    for (int i = 0; i < n; ++i)
    {
        cin >> city[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> c1 >> c2 >> l;
        matrix[c1][c2] = matrix[c2][c1] = l;
    }

    visit[st] = true;
    dfs(0, city[st], st);
    visit[st] = false;

    cout << sc << " " << mc << endl;
    return 0;
}
