/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168


题目
1007 Maximum Subsequence Sum (25分)


思路
双指针即可，代码很快写出来了，但是被0和负数这种情况困了快一个小时。。。
*/


#include <iostream>
using namespace std;
int nums[10010];
int K, cur_i, cur_j, cur_sum, max_i, max_j, max_sum; 
bool exist_zero;

int main() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> nums[i];
        if (nums[i] == 0) {
            exist_zero = true;
        }
    }
    while (cur_i < K && cur_j < K) {
        cur_sum += nums[cur_j];
        if (cur_sum > max_sum) {
            max_i = cur_i;
            max_j = cur_j;
            max_sum = cur_sum;
        }
        if (cur_sum < 0) {
            cur_sum = 0;
            cur_i = cur_j + 1;
        }
        cur_j++;
    }
    if (max_sum == 0) {
        if (exist_zero) {  // 全0|0和负数
            cout << 0 << " " << 0 << " " << 0;
        } else {  // 全负数
            cout << 0 << " " << nums[0] << " " << nums[K - 1];
        }
    } else {
        cout << max_sum << " " << nums[max_i] << " " << nums[max_j];
    }
}
