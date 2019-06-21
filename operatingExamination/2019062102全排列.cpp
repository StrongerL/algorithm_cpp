/*
全排列

https://www.nowcoder.com/practice/5632c23d0d654aecbc9315d1720421c1?tpId=40&tqId=21374&tPage=3&rp=3&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

时间限制：1秒 空间限制：65536K 热度指数：6655

题目描述
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。
输入描述:
输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
输出描述:
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：
已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。

每组样例输出结束后要再输出一个回车。
示例1
输入
abc
输出
abc
acb
bac
bca
cab
cba

注意：直接输出的话并不是字典序

 */



#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char s[10];
int n;
vector<string> ans;

void permutation(int p) {
    
    if (p == n - 1) {
        ans.push_back(s);
        return;
    }
    
    for (int i = p; i < n; i++) {
        swap(s[i], s[p]);
        permutation(p + 1);
        swap(s[i], s[p]);
    }
    
}

int main() {
    while (cin >> s) {
        ans.clear();
        n = strlen(s);
        permutation(0);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
        cout << endl;
    }
}
