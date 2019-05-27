// #include <iostream>
// #include <cstring>
// using namespace std;
// int main() {
    
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int n;
    int* vis;
    queue<int> q;
    int res;
    
    bool validate(int i) {
        return i >= 0 && vis[i];
    } 
    
    int bfs() {
        vis[n] = 1;
        q.push(n);
        int cur, next, len;
        while (!q.empty()) {
            
            len = q.size();
            for (int l = 0; l < len; l++) {
                cur = q.front();
                q.pop();
                int i = sqrt(cur);
                for (; i >= 1; i--) {
                    next = cur - i * i;
                    if (validate(next)) {
                        if (next == 0)
                            return res + 1;
                        q.push(next);
                    }
                }
            }
            
            res++;
        }
        return -1;
    }
    
    int numSquares(int n) {
        this -> n = n;
        int v[n];
        memset(v, 0, sizeof(v));
        vis = v;
        res = 0;
        return bfs();
    }
};