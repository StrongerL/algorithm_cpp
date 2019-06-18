/*

https://www.nowcoder.com/practice/068df51950624be8a14ec08cc02d926e?tpId=40&tqId=21362&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

W's cipher

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����782

��Ŀ����
Weird Wally's Wireless Widgets, Inc. manufactures an eclectic assortment of small, wireless, network capable devices, ranging from dog collars, to pencils, to fishing bobbers. All these devices have very small memories. Encryption algorithms like Rijndael, the candidate for the Advanced Encryption Standard (AES) are demonstrably secure but they don't fit in such a tiny memory. In order to provide some security for transmissions to and from the devices, WWWW uses the following algorithm, which you are to implement. Encrypting a message requires three integer keys, k1, k2, and k3. The letters [a-i] form one group, [j-r] a second group, and everything else ([s-z] and underscore) the third group. Within each group the letters are rotated left by ki positions in the message. Each group is rotated independently of the other two. Decrypting the message means doing a right rotation by ki positions within each group. Consider the message the_quick_brown_fox encrypted with ki values of 2, 3 and 1. The encrypted string is _icuo_bfnwhoq_kxert. The figure below shows the decrypting right rotations for one character in each of the three character groups.

Looking at all the letters in the group [a-i] we see {i,c,b,f,h,e} appear at positions {2,3,7,8,11,17} within the encrypted message. After a right rotation of k1=2, these positions contain the letters {h,e,i,c,b,f}. The table below shows the intermediate strings that come from doing all the rotations in the first group, then all rotations in the second group, then all the rotations in the third group. Rotating letters in one group will not change any letters in any of the other groups.

All input strings contain only lowercase letters and underscores(_). Each string will be at most 80 characters long. The ki are all positive integers in the range 1-100.
��������:
Input consists of information for one or more encrypted messages. Each problem begins with one line containing k1, k2, and k3 followed by a line containing the encrypted message. The end of the input is signalled by a line with all key values of 0.
�������:
For each encrypted message, the output is a single line containing the decrypted string.
ʾ��1
����
2 3 1
_icuo_bfnwhoq_kxert
1 1 1
bcalmkyzx
3 7 4
wcb_mxfep_dorul_eov_qtkrhe_ozany_dgtoh_u_eji
2 4 3
cjvdksaltbmu
0 0 0
���
the_quick_brown_fox
abcklmxyz
the_quick_brown_fox_jumped_over_the_lazy_dog
ajsbktcludmv

���⣺
������������k1, k2, k3 �ͼ��ܺ���ַ�����Ҫ��������ܺ���ַ�����k1,k2,k3��Ϊ0ʱֹͣ���롣
�ַ����е��ַ�����Сд��ĸ���»��ߣ���Ϊ���ࣺ1. [a - i]  2.[j - r]  3.[s - z] �� '_'
���ܵ��㷨������ÿһ���ַ����ֱ��ڱ����������ki����{i,c,b,f,h,e}��k1 = 2����ô����2λ֮��Ϊ{h,e,i,c,b,f}

�������ƣ�
ÿ���ַ����ַ����80���� 1 <= ki <= 100��

˼·��
�ֱ�ʹ�������ַ����洢�����ַ�������int����洢�����ַ���ԭ�ַ����е�λ�ã�
�������ַ�ȡ������ת����ʵ���ǰѺ�ߵ�һ�����ַ��е�ǰ��
����λ�÷Ż������ַ������

*/

#include <iostream>
using namespace std;

string s;
int k1, k2, k3;

// �����ַ���Ӧλ��
int g1[90];
int g2[90];
int g3[90];

// �ж��ַ����
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

        // ȡ�������ַ�
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
        
        // ��ת
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
        
        // �Ż�
        for (int i = 0; i < p1; i++) {
            s[ g1[i] ] = s1[i];
        }
        for (int i = 0; i < p2; i++) {
            s[ g2[i] ] = s2[i];
        }
        for (int i = 0; i < p3; i++) {
            s[ g3[i] ] = s3[i];
        }
        
        // ���
        cout << s << endl;
    }
}
