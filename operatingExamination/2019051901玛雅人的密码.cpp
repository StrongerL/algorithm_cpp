/*
https://www.nowcoder.com/practice/761fc1e2f03742c2aa929c19ba96dbb0?tpId=40&tqId=21343&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking


时间限制：1秒 空间限制：65536K 热度指数：5416

题目描述
玛雅人有一种密码，如果字符串中出现连续的2012四个数字就能解开密码。给一个长度为N的字符串，（2=<N<=13）该字符串中只含有0,1,2三种数字，问这个字符串要移位几次才能解开密码，每次只能移动相邻的两个数字。例如02120经过一次移位，可以得到20120,01220,02210,02102，其中20120符合要求，因此输出为1.如果无论移位多少次都解不开密码，输出-1。
输入描述:
输入包含多组测试数据，每组测试数据由两行组成。
第一行为一个整数N，代表字符串的长度（2<=N<=13）。
第二行为一个仅由0、1、2组成的，长度为N的字符串。
输出描述:
对于每组测试数据，若可以解出密码，输出最少的移位次数；否则输出-1。
示例1
输入
5
02120
输出
1



思路：bfs，每个选择为每一位都移动一次
    每个字符串都是一个节点

*/


#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

// 检验字符串中是否含有2012
bool validate(string s) {
    return s.find("2012") != string::npos;
}

// 交换i与i+1位置的字符
string swap(string s, int i) {
    string tmp = s;
    char t = tmp[i];
    tmp[i] = tmp[i + 1];
    tmp[i + 1] = t;
    return tmp;
}

// 广度优先搜索，节点是一个字符串
int bfs(string s) {
    // 记录交换次数
    map<string, int> m;
    // 存储需要继续交换的字符串
    queue<string> q;
    q.push(s);
    m[s] = 0;
    string tmp;
    while (!q.empty()) {
        s = q.front();
        q.pop();
        // 字符串s交换一次能到达的所有可能节点
        for (int i = 0; i < s.size() - 1; i++) {
            tmp = swap(s, i);
            // 如果字符串是新出现的
            if (m.find(tmp) == m.end()) {
                // 含有2012
                if (validate(tmp))
                    return m[s] + 1;
                // 不含2012，则加入队列继续交换
                else {
                    m[tmp] = m[s] + 1;
                    q.push(tmp);
                }
            } 
        }
    }
    return -1;
}

int main() {
    int N;
    string s;
    while (cin >> N >> s) {
        if (N < 4) {
            cout << -1 << endl;
            continue;
        }
        if (validate(s))
            cout << 0 << endl;
        else
            cout << bfs(s) << endl;
    }
}
