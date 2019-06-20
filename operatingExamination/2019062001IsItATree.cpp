/*
Is it a tree?

https://www.nowcoder.com/practice/1c5fd2e69e534cdcaba17083a5c56335?tpId=40&tqId=21365&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

时间限制：1秒 空间限制：32768K 热度指数：2696

题目描述
A tree is a well-known data structure that is either empty (null, void, nothing) or is a set of one or more nodes connected by directed edges between nodes satisfying the following properties. There is exactly one node, called the root, to which no directed edges point. Every node except the root has exactly one edge pointing to it. There is a unique sequence of directed edges from the root to each node. For example, consider the illustrations below, in which nodes are represented by circles and edges are represented by lines with arrowheads. The first two of these are trees, but the last is not.

In this problem you will be given several descriptions of collections of nodes connected by directed edges. For each of these you are to determine if the collection satisfies the definition of a tree or not.
输入描述:
The input will consist of a sequence of descriptions (test cases) followed by a pair of negative integers. Each test case will consist of a sequence of edge descriptions followed by a pair of zeroes Each edge description will consist of a pair of integers; the first integer identifies the node from which the edge begins, and the second integer identifies the node to which the edge is directed. Node numbers will always be greater than zero and less than 10000.
输出描述:
For each test case display the line "Case k is a tree." or the line "Case k is not a tree.", where k corresponds to the test case number (they are sequentially numbered starting with 1).
示例1
输入
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0
-1 -1
输出
Case 1 is a tree.
Case 2 is a tree.
Case 3 is not a tree.

题意：判断是否是树

思路：树的根节点入度为0，其他节点为1，虽然可以过，但是其实不能判断不连通的情况如1 2 3 4 4 5 5 3 0 0 
    需要改进


 */

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int a, b;
    int t = 0;
    while (cin >> a >> b && (a != -1)) {
        t++;
        map<int, int> m;
        set<int> s;
        while (a) {
            s.insert(a);
            s.insert(b);
            if (m.find(b) == m.end()) {
                m[b] = 1;
            } else {
                m[b] = m[b] + 1;
            }
            cin >> a >> b;
        }
        
        int zero = 0;
        bool isTree = true;
        
        set<int>::iterator it;
        for (it = s.begin(); it != s.end(); it++) {
            if (m.find(*it) != m.end()) {
                if (m[*it] > 1) {
                    isTree = false;
                    break;
                }
            } else {
                zero++;
            }
        }
        
        if (isTree && zero == 1 || !zero && !m.size()) {
            cout << "Case " << t << " is a tree." << endl;
        } else {
            cout << "Case " << t << " is not a tree." << endl;
        }
    }
}
