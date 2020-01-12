/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928


题目
1006 Sign In and Sign Out (25分)
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.

Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.
Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133


思路
直接进行字符串比较就可以了。
ps. 真是是对自己无语了，代码很快写出来了，用例1一直过不了，找了快一个钟头，发现只记得更新登入登出的id忘记更新对应的时间了。。。这样大的错误居然只有用例1没过。。。
*/


#include <iostream>
#include <string>
using namespace std;
int M;
string cur_id, cur_in, cur_out;
string lock_id, unlock_id, lock_time, unlock_time;

bool earlier(string t1, string t2) {
    return t1 < t2;
}

int main() {
    cin >> M;
    cin >> cur_id >> cur_in >> cur_out;
    lock_id = cur_id;
    unlock_id = cur_id;
    unlock_time = cur_in;
    lock_time = cur_out;

    for (int i = 1; i < M; i++) {
        cin >> cur_id >> cur_in >> cur_out;
        if (earlier(cur_in, unlock_time)) {
            unlock_id = cur_id;
            unlock_time = cur_in;
        }
        if (earlier(lock_time, cur_out)) {
            lock_id = cur_id;
            lock_time = cur_out;
        }
    }
    cout << unlock_id << " " << lock_id;
}
