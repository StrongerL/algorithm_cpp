/*
bfs经典情况
油田问题，即找到一个图上的联通的地方有几个
迷宫问题，给出起点终点，问到达终点最少移动次数，可能会对步伐设置不同权值，这样的话使用优先队列即可
其他变形，识别状态和每个状态可以做出的选择很关键

bfs常用数据结构
队列存储接下来要访问的节点
数组存储是否访问过 | 也可以用map，map既可以存储访问标识，还可以存储步数
状态：自定义类（比较灵活，还可以存储步数） | pair | 哈希映射




*/
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;


class State{
    int x;
    int y;
    int step;



};


#define maxn 1001
int n;


int vis[maxn][maxn];
char f[maxn][maxn];

bool validate(State s) {

}



int main() {
    
}

