/*
https://vjudge.net/contest/209344#problem/E

E - Prime Path POJ - 3126 

The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit room numbers on their offices. 
！ It is a matter of security to change such things every now and then, to keep the enemy in the dark. 
！ But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know! 
！ I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door. 
！ No, it¨s not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime! 
！ I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds. 
！ Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime. 

Now, the minister of finance, who had been eavesdropping, intervened. 
！ No unnecessary expenditure, please! I happen to know that the price of a digit is one pound. 
！ Hmm, in that case I need a computer program to minimize the cost. You don't know some very cheap software gurus, do you? 
！ In fact, I do. You see, there is this programming contest going on... Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is a solution in the case above. 
1033 
1733 
3733 
3739 
3779 
8779 
8179
The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step �C a new 1 must be purchased.
Input
One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. Both numbers are four-digit primes (without leading zeros).
Output
One line for each case, either with a number stating the minimal cost or containing the word Impossible.
Sample Input
3
1033 8179
1373 8017
1033 1033
Sample Output
6
7
0


Time limit      1000 ms
Memory limit    65536 kB
OS              Linux
Source          Northwestern Europe 2006

籾吭�左�竃曾倖殆方��貫及匯倖殆方欺及屈倖殆方恷富俶勣謹富肝個延��
      匯肝峪嬬個延匯倖方忖遇拝個延朔議方忖匆駅倬頁殆方。

房揃�� bfs 

*/

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

bool isPrime(string s) {
    // 音嬬聞喘stoi
    int num = (s[0] - '0') * 1000 +
              (s[1] - '0') * 100 +
              (s[2] - '0') * 10 +
              (s[3] - '0') * 1;
    // sqrt遊猟周<cmath>��歌方岷俊int氏竃危
    for (int i = 2; i <= sqrt((double)num); i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}


int bfs(string s1, string s2) {
    queue<string> q;
    // 屡贋刈肝方��匆割輝恵諒炎芝
    map<string, int> m;
    if (s1 == s2) {
        return 0;
    }
    q.push(s1);
    m[s1] = 0;
    while (!q.empty()) {
        string s = q.front();
        q.pop();      
        for (int i = 0; i < 4; i++) {
            // '0'議ASCII鷹頁48
            for (int j = 48; j < 58; j++) {
                // 遍了音葎0
                if (i == 0 && j == 48 || s[i] == j)
                    continue;
                string tmp = s;
                tmp[i] = j;
                if (m.find(tmp) == m.end()) {
                    if (tmp == s2)
                        return m[s] + 1;
                    if (isPrime(tmp)) {
                        m[tmp] = m[s] + 1;
                        q.push(tmp);
                    } else {
                        m[tmp] = -1;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    string s1, s2;
    cin >> n;
    while (n--) {
        cin >> s1 >> s2;
        int res = bfs(s1, s2);
        cout << res << endl;
    }
    return 0;
}
