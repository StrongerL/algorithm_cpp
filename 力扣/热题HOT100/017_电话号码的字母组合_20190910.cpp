/*
17. 电话号码的字母组合
难度 中等
给定一个仅包含数字?2-9?的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射与电话按键相同。注意 1 不对应任何字母。


示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


思路：递归
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
