/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016


题目
1008 Elevator (20分)
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41

思路
这段时间自己怎么这么蠢，电梯下降时tmp的符号都忘记改成减号。。。
*/


#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int time = 0;
    int requests[N];
    for (int i = 0; i < N; i++) {
        cin >> requests[i];
    }
    time += 5 * N;
    time += 6 * requests[0];
    for (int i = 1; i < N; i++) {
        int tmp = requests[i] - requests[i - 1];
        if (tmp >= 0) {
            time += 6 * tmp;
        } else {
            time -= 4 * tmp;
        }
    }
    cout << time;
}
