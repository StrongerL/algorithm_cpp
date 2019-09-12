/*
31. 下一个排列
难度 中等
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。


以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


思路：1. 一遍扫描；2.api
*/


#include <vector>
using namespace std;

class Solution {
public:
    // 一遍扫描
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i >= 1) {
            if (nums[i] > nums[i - 1])
                break;
            i--;
        }
        
        for (int j = nums.size() - 1; j >= i && i > 0; j--) {
            if (nums[j] > nums[i - 1]) {
                swap(nums[i - 1], nums[j]);
                break;
            }
        }
        for (int j = i; j < (nums.size() + i) / 2; j++) {
            swap(nums[j], nums[nums.size() + i - j - 1]);
        }
    }
    
    // 骚操作
	// void nextPermutation(vector<int>& nums) {
	// 	next_permutation(nums.begin(), nums.end());
	// }
};
