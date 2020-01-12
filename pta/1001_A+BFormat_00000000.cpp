/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400


题目
1001 A+B Format (20分)
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where (−10)^6​​ <= a,b <=(10)^6. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9
Sample Output:
-999,991


思路
*/


#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, sum;
    string s;
    cin >> a >> b;
    sum = a + b;
    s = to_string(sum);
    for (int i = s.length() - 3; i >= 1; i = i - 3) {
        s.insert(i, ",");
    }
    if (s.length() > 1 && s[0] == '-' && s[1] == ',') {
        s.erase(1, 1);
    }
    cout << s;

    return 0;
}
