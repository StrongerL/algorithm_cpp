/*
Freckles

https://www.nowcoder.com/practice/41b14b4cd0e5448fb071743e504063cf?tpId=40&tqId=21371&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

时间限制：1秒 空间限制：65536K 热度指数：2411

题目描述
    In an episode of the Dick Van Dyke show, little Richie connects the freckles on his Dad's back to form a picture of the Liberty Bell. Alas, one of the freckles turns out to be a scar, so his Ripley's engagement falls through.      Consider Dick's back to be a plane with freckles at various (x,y) locations. Your job is to tell Richie how to connect the dots so as to minimize the amount of ink used. Richie connects the dots by drawing straight lines between pairs, possibly lifting the pen between lines. When Richie is done there must be a sequence of connected lines from any freckle to any other freckle.
输入描述:
    The first line contains 0 < n <= 100, the number of freckles on Dick's back. For each freckle, a line follows; each following line contains two real numbers indicating the (x,y) coordinates of the freckle.
输出描述:
    Your program prints a single real number to two decimal places: the minimum total length of ink lines that can connect all the freckles.
示例1
输入
3
1.0 1.0
2.0 2.0
2.0 4.0
输出
3.41

题意：连接所有点的最短长度

思路：dijstra，不过似乎是最小生成树


 */

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

struct Point {
    double x;
    double y;
};

Point points[110];
int red[110];
int n;

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool bingo() {
    for (int i = 0; i < n; i++) {
        if (!red[i])
            return false;
    }
    return true;
}

double dijstra() {
    double dis = 0;
    while (!bingo()) {
        double minDistance = -1;
        double tmp;
        int index;
        for (int i = 0; i < n; i++) {
            if (red[i]) {
                for (int j = 0; j < n; j++) {
                    if (!red[j]) {
                        tmp = distance(points[i], points[j]);
                        if (tmp < minDistance || minDistance < 0) {
                            minDistance = tmp;
                            index = j;
                        }
                    }
                }
            }
        }
        red[index] = 1;
        dis += minDistance;
    }
    return dis;
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            red[i] = 0;
            cin >> points[i].x >> points[i].y;
        }
        red[0] = 1;
        
        cout << fixed << setprecision(2) << dijstra() << endl;
    }
}
