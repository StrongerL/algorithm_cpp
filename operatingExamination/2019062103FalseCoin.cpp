/*
False coin

时间限制：1秒 空间限制：65536K 热度指数：1277

题目描述
The "Gold Bar"bank received information from reliable sources that in their last group of N coins exactly one coin is false and differs in weight from other coins (while all other coins are equal in weight). After the economic crisis they have only a simple balance available (like one in the picture). Using this balance, one is able to determine if the weight of objects in the left pan is less than, greater than, or equal to the weight of objects in the right pan. In order to detect the false coin the bank employees numbered all coins by the integers from 1 to N, thus assigning each coin a unique integer identifier. After that they began to weight various groups of coins by placing equal numbers of coins in the left pan and in the right pan. The identifiers of coins and the results of the weightings were carefully recorded. You are to write a program that will help the bank employees to determine the identifier of the false coin using the results of these weightings.
输入描述:
The first line of the input file contains two integers N and K, separated by spaces, where N is the number of coins (2<=N<=1000 ) and K is the number of weightings fulfilled (1<=K<=100). The following 2K lines describe all weightings. Two consecutive lines describe each weighting. The first of them starts with a number Pi (1<=Pi<=N/2), representing the number of coins placed in the left and in the right pans, followed by Pi identifiers of coins placed in the left pan and Pi identifiers of coins placed in the right pan. All numbers are separated by spaces. The second line contains one of the following characters: '<', '>', or '='. It represents the result of the weighting:
'<' means that the weight of coins in the left pan is less than the weight of coins in the right pan,
'>' means that the weight of coins in the left pan is greater than the weight of coins in the right pan,
'=' means that the weight of coins in the left pan is equal to the weight of coins in the right pan.
输出描述:
Write to the output file the identifier of the false coin or 0, if it cannot be found by the results of the given weightings.
示例1
输入
5 3
2 1 2 3 4
<
1 1 4
=
1 2 5
=
输出
3

 */

#include <iostream>
#include <cstring>
using namespace std;

/*
硬币的四种状态
0 没称过
-1 在轻的一方出现过
1 在重的一方出现过
2 为真
*/

int n, k;
int coins[1010];
int balance[1010];
int p;
char c;

// 判断num是否在大小为n的天平中
bool inBalance(int n, int num) {
    for (int i = 0; i < n; i++) {
        if (balance[i] == num) 
            return true;
    }
    return false;
}


int main() {
    while (cin >> n >> k) {
        memset(coins, 0, sizeof(coins));
        for (int t = 0; t < k; t++) {
            cin >> p;
            for (int i = 0; i < 2 * p; i++) {
                cin >> balance[i];
            }
            cin >> c;
            
            // 如果天平等于，那么天平中的所有硬币为真
            if (c == '=') {
                for (int i = 0; i < 2 * p; i++) {
                    coins[balance[i]] = 2;
                }
            } else {
                // 如果天平不平衡，轻的一方赋值-1，重的一方赋值1
                int sign = (c == '<') ? 1 : -1;
                for (int i = 0; i < p; i++) {
                    // 硬币如果已经判断为真或者既在轻的一方出现过又在重的一方出现过，那么这个硬币为真
                    if (coins[balance[i]] == 2 || coins[balance[i]] - sign == 0) {
                        coins[balance[i]] = 2;
                    } else {
                        coins[balance[i]] = (-sign);
                    }
                }
                for (int i = p; i < 2 * p; i++) {
                    if (coins[balance[i]] == 2 || coins[balance[i]] + sign == 0) {
                        coins[balance[i]] = 2;
                    } else {
                        coins[balance[i]] = sign;
                    }
                }
                
                // 不在天平中的硬币为真
                for (int i = 1; i <= n; i++) {
                    if (!inBalance(2 * p, i))
                        coins[i] = 2;
                }
            }
        }

        // 如果只有一个不是真，那么该硬币为假，否则无法判断
        int index;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (coins[i] != 2) {
                  count++;
                  index = i;
             }
        }
        if (count == 1)
            cout << index << endl;
        else
            cout << 0 << endl;
    }
}
