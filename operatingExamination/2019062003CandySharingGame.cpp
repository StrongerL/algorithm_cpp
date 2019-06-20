/*
Candy Sharing Game

https://www.nowcoder.com/practice/33adf53e095440b2823a39146a285b77?tpId=40&tqId=21369&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

时间限制：1秒 空间限制：65536K 热度指数：1703

题目描述
A number of students sit in a circle facing their teacher in the center. Each student initially has an number of pieces of candy. When the teacher blows a whistle, each student simultaneously gives half of his or her candy to the neighbor on the right. Any student, who ends up with an odd number of pieces of candy, is given another piece by the teacher. The game ends when all students have the same number of pieces of candy. Write a program which determines the number of times the teacher blows the whistle and the final number of pieces of candy for each student from the amount of candy each child starts with.
输入描述:
The input may describe more than one game. For each game, the input begins with the number N of students,followed by N candy counts for the children counter-clockwise around the circle.  Each input number is on a line by itself.
输出描述:
For each game, output the number of rounds of the game followed by the amount of candy each child ends up with,both on one line. 

The game ends in a finite number of steps because:
1. The maximum candy count can never increase.
2. The minimum candy count can never decrease.
3. No one with more than the minimum amount will ever decrease to the minimum.
4. If the maximum and minimum candy count are not the same, at least one student with the minimum amount must have their count increase
示例1
输入
6
36
2
2
2
2
2
输出
15 14


注意：开始的数可能为奇数，如果为3，那就给3 / 2 = 1个给右边

 */


#include <iostream>
using namespace std;

bool isEqual(int nums[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] != nums[i + 1])
            return false;
    }
    return true;
}

int main () {
    int n, tmp;
    while (cin >> n) {
        int nums[n];
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        int tmp;
        int count = 0;
        while (!isEqual(nums, n)) {
            count++;
            tmp = nums[n - 1] / 2;
            nums[n - 1] -= tmp;
            for (int i = n - 1; i > 0; i--) {
                nums[i] += nums[i - 1] / 2;
                nums[i - 1] = (nums[i - 1] + 1) /2;
                if (nums[i] & 1)
                    nums[i]++;
            }
            nums[0] += tmp;
            if (nums[0] & 1)
                nums[0]++;
        }
        
        cout << count << " " << nums[0] << endl;
    }
}
