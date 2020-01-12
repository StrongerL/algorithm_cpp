/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336

题目
1005 Spell It Right (20分)
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<=10^100).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

思路
*/


#include <iostream>
#include <string>
using namespace std;

string N;
int sum;
string num2str[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    cin >> N;
    for (int i = 0; i < N.length(); i++) {
        sum += N[i] - '0';
    }
    string ans = to_string(sum);
    cout << num2str[ans[0] - '0'];
    for (int i = 1; i < ans.length(); i++) {
        cout << " " << num2str[ans[i] - '0'];
    }
}
