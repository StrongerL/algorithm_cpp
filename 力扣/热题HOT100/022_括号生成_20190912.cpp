/*
22. ��������
�Ѷ� �е�
����?n?�����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�


���磬����?n = 3�����ɽ��Ϊ��
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/generate-parentheses
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


˼·������
https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode/
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) {
        GetAns("", 0, 0, n);
        return ans;
    }
    
    void GetAns(string cur, int left, int right, int n) {
        if (cur.length() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (left < n) {
            GetAns(cur + "(", left + 1, right, n);
        }
        if (left > right) {
            GetAns(cur + ")", left, right + 1, n);
        }
    }
};
