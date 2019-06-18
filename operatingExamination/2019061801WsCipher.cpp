/*

https://www.nowcoder.com/practice/068df51950624be8a14ec08cc02d926e?tpId=40&tqId=21362&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

W's cipher

时间限制：1秒 空间限制：65536K 热度指数：782

题目描述
Weird Wally's Wireless Widgets, Inc. manufactures an eclectic assortment of small, wireless, network capable devices, ranging from dog collars, to pencils, to fishing bobbers. All these devices have very small memories. Encryption algorithms like Rijndael, the candidate for the Advanced Encryption Standard (AES) are demonstrably secure but they don't fit in such a tiny memory. In order to provide some security for transmissions to and from the devices, WWWW uses the following algorithm, which you are to implement. Encrypting a message requires three integer keys, k1, k2, and k3. The letters [a-i] form one group, [j-r] a second group, and everything else ([s-z] and underscore) the third group. Within each group the letters are rotated left by ki positions in the message. Each group is rotated independently of the other two. Decrypting the message means doing a right rotation by ki positions within each group. Consider the message the_quick_brown_fox encrypted with ki values of 2, 3 and 1. The encrypted string is _icuo_bfnwhoq_kxert. The figure below shows the decrypting right rotations for one character in each of the three character groups.

Looking at all the letters in the group [a-i] we see {i,c,b,f,h,e} appear at positions {2,3,7,8,11,17} within the encrypted message. After a right rotation of k1=2, these positions contain the letters {h,e,i,c,b,f}. The table below shows the intermediate strings that come from doing all the rotations in the first group, then all rotations in the second group, then all the rotations in the third group. Rotating letters in one group will not change any letters in any of the other groups.

All input strings contain only lowercase letters and underscores(_). Each string will be at most 80 characters long. The ki are all positive integers in the range 1-100.
输入描述:
Input consists of information for one or more encrypted messages. Each problem begins with one line containing k1, k2, and k3 followed by a line containing the encrypted message. The end of the input is signalled by a line with all key values of 0.
输出描述:
For each encrypted message, the output is a single line containing the decrypted string.
示例1
输入
2 3 1
_icuo_bfnwhoq_kxert
1 1 1
bcalmkyzx
3 7 4
wcb_mxfep_dorul_eov_qtkrhe_ozany_dgtoh_u_eji
2 4 3
cjvdksaltbmu
0 0 0
输出
the_quick_brown_fox
abcklmxyz
the_quick_brown_fox_jumped_over_the_lazy_dog
ajsbktcludmv

题意：
输入三个数字k1, k2, k3 和加密后的字符串，要求输出解密后的字符串，k1,k2,k3均为0时停止输入。
字符串中的字符包括小写字母和下划线，分为三类：1. [a - i]  2.[j - r]  3.[s - z] 和 '_'
解密的算法：对于每一类字符，分别在本类别中右移ki，如{i,c,b,f,h,e}，k1 = 2，那么右移2位之后为{h,e,i,c,b,f}

输入限制：
每个字符串字符最多80个， 1 <= ki <= 100。

思路：
分别使用三个字符串存储三类字符，三个int数组存储三类字符在原字符串中的位置，
将三类字符取出后旋转，其实就是把后边的一部分字符切到前边
根据位置放回三类字符，输出

*/

#include <iostream>
using namespace std;

string s;
int k1, k2, k3;

// 三类字符对应位置
int g1[90];
int g2[90];
int g3[90];

// 判断字符类别
int group(char c) {
    if (c >= 'a' && c <= 'i')
        return 1;
    else if (c >= 'j' && c <= 'r')
        return 2;
    else
        return 3;
}

int main() {
    while (cin >> k1 >> k2 >> k3 && (k1 || k2 || k3)) {
        cin >> s;

        // 取出三类字符
        int p1 = 0, p2 = 0, p3 = 0;
        string s1 = "", s2 = "", s3 = "";
        for (int i = 0; i < s.length(); i++) {
            if (group(s[i]) == 1) {
                s1 += s[i];
                g1[p1++] = i;
            } else if (group(s[i]) == 2) {
                s2 += s[i];
                g2[p2++] = i;
            } else {
                s3 += s[i];
                g3[p3++] = i; 
            }
        }
        
        // 旋转
        if (k1 * p1) {
            k1 = k1 % p1;
            s1 = s1.substr(p1 - k1, p1) + s1.substr(0, p1 - k1);
        }
        if (k2 * p2) {
            k2 = k2 % p2;
            s2 = s2.substr(p2 - k2, p2) + s2.substr(0, p2 - k2);
        }   
        if (k3 * p3) {
            k3 = k3 % p3;
            s3 = s3.substr(p3 - k3, p3) + s3.substr(0, p3 - k3);
        }
        
        // 放回
        for (int i = 0; i < p1; i++) {
            s[ g1[i] ] = s1[i];
        }
        for (int i = 0; i < p2; i++) {
            s[ g2[i] ] = s2[i];
        }
        for (int i = 0; i < p3; i++) {
            s[ g3[i] ] = s3[i];
        }
        
        // 输出
        cout << s << endl;
    }
}
