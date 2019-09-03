/*
3. 无重复字符的最长子串
难度 中等
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。

示例1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是?"wke"，所以其长度为 3。
    请注意，你的答案必须是 子串 的长度，"pwke"是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


思路：
滑动窗口
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetcod/

*/

// #include <set>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 初始版
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

        // 优化版
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
