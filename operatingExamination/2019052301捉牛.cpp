/*
https://vjudge.net/contest/209344#problem/G

G - Catch That Cow HDU - 2717 

Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting. 

* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute 
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute. 

If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?
Input
Line 1: Two space-separated integers: N and K
Output
Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.
Sample Input
5 17
Sample Output
4


        
  
Hint
The fastest way for Farmer John to reach the fugitive cow is to move along the following path: 5-10-9-18-17, which takes 4 minutes.


Time limit      2000 ms
Memory limit    32768 kB
OS              Windows
Source          USACO 2007 Open Silver

题意：给出自己当前位置n，牛的位置k，从一个位置到另一个位置只能是+1、-1、*2。
      最少移动几次可以找到牛。

思路：bfs

*/


#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

int n, k;
map<int, int> m;
queue<int> q;

bool validate(int i) {
    return i >= 0 && i <= 100000 && m.find(i) == m.end();
}

int bfs() {
    if (n == k)
        return 0;
    q.push(n);
    m[n] = 0;
    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (validate(cur - 1)) {
            if (cur - 1 == k)
                return m[cur] + 1;
            q.push(cur - 1);
            m[cur - 1] = m[cur] + 1;
        }

        if (validate(cur + 1)) {
            if (cur + 1 == k)
                return m[cur] + 1;
            q.push(cur + 1);
            m[cur + 1] = m[cur] + 1;
        }

        if (validate(cur * 2)) {
            if (cur * 2 == k)
                return m[cur] + 1;
            q.push(cur * 2);
            m[cur * 2] = m[cur] + 1;
        }

    }

    return -1;
}

int main() {

    while (cin >> n >> k) {
        m.clear();
        while (!q.empty())
            q.pop();
        cout << bfs() << endl;
    }

}
