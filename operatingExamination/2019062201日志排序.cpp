/*
日志排序

https://www.nowcoder.com/practice/0f64518fea254c0187ccf0ea05019672?tpId=40&tqId=21363&tPage=2&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

时间限制：1秒 空间限制：65536K 热度指数：4413

题目描述
有一个网络日志，记录了网络中计算任务的执行情况，每个计算任务对应一条如下形式的日志记录： “hs_10000_p”是计算任务的名称， “2007-01-17 19:22:53,315”是计算任务开始执行的时间“年-月-日 时：分：秒，毫秒”， “253.035(s)”是计算任务消耗的时间(以秒计) hs_10000_p 2007-01-17 19:22:53,315 253.035(s) 请你写一个程序，对日志中记录计算任务进行排序。 时间消耗少的计算任务排在前面，时间消耗多的计算任务排在后面。 如果两个计算任务消耗的时间相同，则将开始执行时间早的计算任务排在前面。
输入描述:
日志中每个记录是一个字符串，每个字符串占一行。最后一行为空行，表示日志结束。日志中最多可能有10000条记录。
计算任务名称的长度不超过10，开始执行时间的格式是YYYY-MM-DD HH:MM:SS,MMM，消耗时间小数点后有三位数字。
计算任务名称与任务开始时间、消耗时间之间以一个或多个空格隔开，行首和行尾可能有多余的空格。
输出描述:
排序好的日志记录。每个记录的字符串各占一行。
输入的格式与输入保持一致，输入包括几个空格，你的输出中也应该包含同样多的空格。
示例1
输入
hs_10000_p   2007-01-17 19:22:53,315     253.035(s)
hs_10001_p   2007-01-17 19:22:53,315     253.846(s)
hs_10002_m   2007-01-17 19:22:53,315     129.574(s)
hs_10002_p   2007-01-17 19:22:53,315     262.531(s)
hs_10003_m   2007-01-17 19:22:53,318     126.622(s)
hs_10003_p   2007-01-17 19:22:53,318     136.962(s)
hs_10005_m   2007-01-17 19:22:53,318     130.487(s)
hs_10005_p   2007-01-17 19:22:53,318     253.035(s)
hs_10006_m   2007-01-17 19:22:53,318     248.548(s)
hs_10006_p   2007-01-17 19:25:23,367    3146.827(s)
输出
hs_10003_m   2007-01-17 19:22:53,318     126.622(s)
hs_10002_m   2007-01-17 19:22:53,315     129.574(s)
hs_10005_m   2007-01-17 19:22:53,318     130.487(s)
hs_10003_p   2007-01-17 19:22:53,318     136.962(s)
hs_10006_m   2007-01-17 19:22:53,318     248.548(s)
hs_10000_p   2007-01-17 19:22:53,315     253.035(s)
hs_10005_p   2007-01-17 19:22:53,318     253.035(s)
hs_10001_p   2007-01-17 19:22:53,315     253.846(s)
hs_10002_p   2007-01-17 19:22:53,315     262.531(s)
hs_10006_p   2007-01-17 19:25:23,367    3146.827(s)

思路：分割字符串，用时转化为double再比较，开始时间直接比较字符串即可

 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct Log {
    string raw;
    string start;
    double t;
    
    bool operator < (const Log& log) const {
        if (t < log.t) {
            return true;
        } else if (t > log.t) {
            return false;
        } else {
            return start < log.start;
        }
    }
    
};

Log logs[10010];
int n;

void stringToLog(string s, Log& log) {
    char cs[s.length() + 1];
    strcpy(cs, s.c_str());
    
    char* tmp;
    string si[4];
    int i = 0;
    
    tmp = strtok(cs, " ");
    while (tmp != NULL) {
        si[i++] = string(tmp);
        tmp = strtok(NULL, " ");    
    }
    
    log.raw = s;
    log.start = si[1] + si[2];
    log.t = stod(si[3].substr(0, si[3].length() - 3));
    
}


int main() {
    string s;
    Log log;
    char* tmp;
    while (getline(cin, s)) {
        stringToLog(s, log);
        logs[n++] = log;
    }
    
    
    sort(logs, logs + n);
    for (int i = 0; i < n; i++) {
        cout << logs[i].raw << endl;
    }
}
