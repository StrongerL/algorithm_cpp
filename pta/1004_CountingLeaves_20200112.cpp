 /*  
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184


题目
1004 Counting Leaves (30分)
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input Specification:
Each input file contains one test case. Each case starts with a line containing 0<N<100, the number of nodes in a tree, and M (<N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
The input ends with N being 0. That case must NOT be processed.
Output Specification:
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output 0 1 in a line.
Sample Input:
2 1
01 1 02
Sample Output:
0 1


思路
题目的含义是求系谱图（可以看作单根的树）每一层中叶子节点的个数。
dfs或者bfs，可以将题中所说的图直接看作树而不是高中时学的家族系谱图。参考了这个网页：
https://blog.csdn.net/CV_Jason/article/details/80901866
*/  


#include <iostream>
#include <vector>
using namespace std;

int N, M;
int max_depth = -1;
int ans[100];
vector<int> v[100];

void dfs(int node, int depth){
    if (v[node].size() == 0) {
        ans[depth]++;
        if (depth > max_depth) {
            max_depth = depth;
        }
        return;
    }
    for (int i = 0; i < v[node].size(); i++) {
        dfs(v[node][i], depth + 1);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int cur, k, tmp;
        cin >> cur >> k;
        while (k > 0) {
            cin >> tmp;
            v[cur].push_back(tmp);
            k--;
        }
    }

    dfs(1, 0);

    cout << ans[0];
    for (int i = 1; i <= max_depth; i++) {
        cout << " " << ans[i];
    }
}
