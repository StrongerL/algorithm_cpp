/*
11. ʢ���ˮ������
�Ѷ� �е�
���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ����?(i,?ai) ���������ڻ� n ����ֱ�ߣ���ֱ�� i?�������˵�ֱ�Ϊ?(i,?ai) �� (i, 0)���ҳ����е������ߣ�ʹ��������?x?�Ṳͬ���ɵ�����������������ˮ��
˵�����㲻����б��������?n?��ֵ����Ϊ 2��


ʾ��:
����: [1,8,6,2,5,4,8,3,7]
���: 49


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/container-with-most-water
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


˼·��˫ָ��
https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode/
*/


#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // ����
        // int max_water = 0;
        // for (int i = 1; i < height.size(); i++) {
        //     for (int j = i - 1; j >= 0; j--) {
        //         int tmp = min(height[i], height[j]) * (i - j);
        //         if (tmp > max_water) {
        //             max_water = tmp;
        //         }
        //     }
        // }
        // return max_water;
        
        // ˫ָ��
        int i = 0, j = height.size() - 1;
        int max_water = 0;
        while (i < j) {
            int cur_water = min(height[i], height[j]) * (j - i);
            if (cur_water > max_water) {
                max_water = cur_water;
            }
            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return max_water;  
    }
};
