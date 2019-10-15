#include <iostream>
#include <math.h>
using namespace std;

void segmentedBitonicSort(float* data, int* seg_id, int* seg_start, int n, int m) {

    bool asd = true;
    for (int i = 0; i < m; ++i) {
        float *arr = data + seg_start[i]; // 数列起点
        int len = seg_start[i + 1] - seg_start[i]; // 数列长度

        // 归并为双调序列  bitonicMerge(arr, len);
        int merge_len = len;
        for (int merge_step = 2; merge_step < merge_len; merge_step *= 2) {
            for (int merge_i = 0; merge_i < merge_len; merge_i += 2 * merge_step) {
                // merge_step为2的幂时数据左半部分和右半部分的长度
                int left_len = merge_step, right_len = merge_step;

                // 左半部分降序 bitonicSort(arr + merge_i, left_len, !asd);
                // 更新左半部分数据长度
                if (merge_len - merge_i < merge_step)
                    left_len = merge_len - merge_i;
                // 找到最大的不大于left_len的p，p为2的幂，确定sort_step大小
                int left_p = 1;
                while (left_p > 0 && left_p < left_len) left_p <<= 1;
                left_p >>= 1;
                int sort_step = left_p;
                if (sort_step == left_len)
                    sort_step >>= 1;
                // 左半部分开头
                float* left_arr = arr + merge_i;
                for (; sort_step > 0; sort_step /= 2) {
                    for (int sort_i = 0; sort_i < left_len; sort_i += 2 * sort_step) { // 2 * step 一组序列
                        for (int j = sort_i; j < sort_i + sort_step && j + sort_step < left_len; ++j) { // 遍历序列内部，i是序列起点
                            if (left_arr[j] < left_arr[j + sort_step] || left_arr[j + sort_step] != left_arr[j + sort_step]) {
                                // swap(left_arr[j], left_arr[j + sort_step])
                                float tmp = left_arr[j];
                                left_arr[j] = left_arr[j + sort_step];
                                left_arr[j + sort_step] = tmp;  
                            }
                        }
                    }
                }

                // 右半部分数据升序 bitonicSort(data + merge_step + merge_i, right_len, asd);
                if (left_len == merge_step) { // 左半部分数据不足，右半部分也没数据
                    // 更新右半部分数据长度
                    if (merge_len - merge_step - merge_i < merge_step)
                        right_len = merge_len - merge_step - merge_i;
                    // 找到最大的不大于right_len的p，p为2的幂，确定sort_step大小
                    int p = 1;
                    while (p > 0 && p < right_len) p <<= 1;
                    p >>= 1;
                    int sort_step = p;
                    if (sort_step == right_len)
                        sort_step >>= 1;
                    // 右半部分开头
                    float* right_arr = arr + merge_step + merge_i;
                    for (; sort_step > 0; sort_step /= 2) {
                        for (int sort_i = 0; sort_i < right_len; sort_i += 2 * sort_step) { // 2 * step 一组序列
                            for (int j = sort_i; j < sort_i + sort_step && j + sort_step < right_len; ++j) { // 遍历序列内部，i是序列起点
                                // swap(arr[j],arr[j + sort_step])
                                if (right_arr[j] > right_arr[j + sort_step] || right_arr[j] != right_arr[j]) {
                                    float tmp = right_arr[j];
                                    right_arr[j] = right_arr[j + sort_step];
                                    right_arr[j + sort_step] = tmp;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        // 升序排序 bitonicSort(arr, len, asd);
        int sort_len = len;
        // 找到最大的不大于 sort_len 的p，p为2的幂，确定sort_step大小
        int sort_p = 1;
        while (sort_p > 0 && sort_p < sort_len) sort_p <<= 1;
        sort_p >>= 1;
        int sort_step = sort_p;
        if (sort_step == sort_len)
            sort_step >>= 1;
        // 排序
        for (; sort_step > 0; sort_step /= 2) {
            for (int sort_i = 0; sort_i < sort_len; sort_i += 2 * sort_step) { // 2 * step 一组序列
                for (int j = sort_i; j < sort_i + sort_step && j + sort_step < sort_len; ++j) { // 遍历序列内部，i是序列起点
                    if (arr[j] > arr[j + sort_step] || arr[j] != arr[j]) {
                        // swap(arr[j],arr[j + sort_step])
                        float tmp = arr[j];
                        arr[j] = arr[j + sort_step];
                        arr[j + sort_step] = tmp;
                    }
                }
            }
        }

        // 输出
        cout << "段 " << i << ": ";
        for (int k = 0; k < len; k++) {
            cout << arr[k] << " ";
        }
        cout << endl << endl;
    }
}

int main() {
    cout << "=================测试用例0===========================" << endl;
    float data0[5] = {0.8, 0.2, 
                      0.4, 0.6, 0.5};
    int seg_id0[5] = {0,   0,   1,   1,   1};
    int seg_start0[3] = {0, 2, 5};
    int n0 = 5;
    int m0 = 2;
    segmentedBitonicSort(data0, seg_id0, seg_start0, n0, m0);
    cout << endl;

    cout << "=================测试用例1===========================" << endl;
    float data1[9] = {0.8, 0.2,
                      0.4, 0.6, 0.5, 
                      0.59, 0.21, 0.57, 
                      0.12};
    int seg_id1[9] = {0,   0,   1,   1,   1,   2,    2,    2,    3};
    int seg_start1[5] = {0, 2, 5, 8, 9};
    int n1 = 9;
    int m1 = 4;
    segmentedBitonicSort(data1, seg_id1, seg_start1, n1, m1);
    cout << endl;

    cout << "=================测试用例2===========================" << endl;
    float data2[9] = {0.8, sqrt(-1.f), 
                      0.4, 0.6, sqrt(-1.f), 
                      0.59, 0.21, sqrt(-1.f), 
                      0.12};
    int seg_id2[9] = {0,   0,   1,   1,   1,   2,    2,    2,    3};
    int seg_start2[5] = {0, 2, 5, 8, 9};
    int n2 = 9;
    int m2 = 4;
    segmentedBitonicSort(data2, seg_id2, seg_start2, n2, m2);
    cout << endl;

    cout << "=================测试用例3===========================" << endl;
    float data3[21] = {1.08344, 2.6747, sqrt(-1.f), 1.94815, 1.11102, 
                      0.289917, 0.64205,
                      6.59573, 0.00369898, 12.7636, 1.56606, 
                      0.0572074, 0.380153, sqrt(-1.f), 2.96348, sqrt(-1.f), 
                      sqrt(-1.f), 2.27465, 1.71466, 3.69074, 0.351484};
    int seg_id3[21] = {0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4};
    int seg_start3[6] = {0, 5, 7, 11, 16, 21};
    int n3 = 21;
    int m3 = 5;
    segmentedBitonicSort(data3, seg_id3, seg_start3, n3, m3);
    cout << endl;

    return 0;
}
