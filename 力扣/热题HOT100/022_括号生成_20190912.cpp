/*
22. 括号生成
难度 中等
给出?n?代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。


例如，给出?n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


思路：回溯
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
