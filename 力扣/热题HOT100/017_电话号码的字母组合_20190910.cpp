/*
17. �绰�������ĸ���
�Ѷ� �е�
����һ������������?2-9?���ַ����������������ܱ�ʾ����ĸ��ϡ�
�������ֵ���ĸ��ӳ����绰������ͬ��ע�� 1 ����Ӧ�κ���ĸ��


ʾ��:
���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
˵��:
��������Ĵ��ǰ��ֵ������еģ��������������ѡ��������˳��


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


˼·���ݹ�
*/


#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string table[8] = {"abc", "def", "ghi",
                      "jkl", "mno", "pqrs", 
                      "tuv", "wxyz"};
    vector<string> ans;
    
    void GetAns(string cur, string digits, int p) {
        if (p == digits.length()) {
            ans.push_back(cur);
            return;
        } else {
            for (int i = 0; i < table[digits[p] - '2'].length(); i++) {
                GetAns(cur + table[digits[p] - '2'][i], digits, p + 1);
            }
        }      
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits != "")
            GetAns("", digits, 0);
        return ans;
    }
};
