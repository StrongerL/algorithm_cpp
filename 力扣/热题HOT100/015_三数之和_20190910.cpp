/*
15. ����֮��
�Ѷ� �е�
����һ������ n ������������?nums���ж�?nums?���Ƿ��������Ԫ�� a��b��c ��ʹ��?a + b + c = 0 �ҳ��������������Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣


����, �������� nums = [-1, 0, 1, 2, -1, -4]��
����Ҫ�����Ԫ�鼯��Ϊ��
[
  [-1, 0, 1],
  [-1, -1, 2]
]


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/3sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

˼·������+˫ָ��
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
