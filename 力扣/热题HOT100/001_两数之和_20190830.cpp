/*
1. ����֮��
�Ѷȼ�
����һ���������� nums��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�


ʾ��:
���� nums = [2, 7, 11, 15], target = 9
��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/two-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


˼·��ʹ��map
*/


#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        m[target - nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end())
                m[target - nums[i]] = i;
            else {
                ans.push_back(m[nums[i]]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};
