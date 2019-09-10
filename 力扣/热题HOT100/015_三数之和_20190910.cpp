/*
15. 三数之和
难度 中等
给定一个包含 n 个整数的数组?nums，判断?nums?中是否存在三个元素 a，b，c ，使得?a + b + c = 0 找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。


例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：排序+双指针
https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {       
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0)  break;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int cur_sum = nums[i] + nums[l] + nums[r];
                if (cur_sum == 0) {
                    vector<int> cur_ans = {nums[i], nums[l], nums[r]};
                    ans.push_back(cur_ans);
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (cur_sum < 0) {
                    l++;
                } else {
                    r--; 
                } 
            }
        }
        return ans;
    }
};
