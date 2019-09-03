/*
3. ���ظ��ַ�����Ӵ�
�Ѷ� �е�
����һ���ַ����������ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�

ʾ��1:
����: "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:
����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:
����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ���?"wke"�������䳤��Ϊ 3��
    ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke"��һ�������У������Ӵ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


˼·��
��������
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetcod/

*/

// #include <set>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // ��ʼ��
        // set<char> set_char;
        // int ans = 0, i = 0, j = 0;
        // while (i < s.length() && j < s.length()) {
        //     if (set_char.find(s[j]) == set_char.end()) {
        //         set_char.insert(s[j++]);
        //         ans = max(ans, j - i);
        //     } else {
        //         set_char.erase(s[i++]);
        //     }
        // }
        // return ans;

        // �Ż���
        map<char, int> m;
        int ans = 0;
        for (int i = 0, j = 0; j < s.length(); j++) {
            if (m.find(s[j]) != m.end()) {
                i = max(i, m[s[j]] + 1);
            }
            ans = max(ans, j - i + 1);
            m[s[j]] = j;
        }
        return ans;
    }
};
