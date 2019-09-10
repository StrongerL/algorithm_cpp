/*
11. 盛最多水的容器
难度 中等
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点?(i,?ai) 。在坐标内画 n 条垂直线，垂直线 i?的两个端点分别为?(i,?ai) 和 (i, 0)。找出其中的两条线，使得它们与?x?轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且?n?的值至少为 2。


示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


思路：双指针
https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode/
*/


#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 暴力
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
        
        // 双指针
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
