/*
31. ��һ������
�Ѷ� �е�
ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�
�����������һ����������У��������������г���С�����У����������У���
����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣


������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/next-permutation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


˼·��1. һ��ɨ�裻2.api
*/


#include <vector>
using namespace std;

class Solution {
public:
    // һ��ɨ��
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
    
    // ɧ����
	// void nextPermutation(vector<int>& nums) {
	// 	next_permutation(nums.begin(), nums.end());
	// }
};
