#include <iostream>
#include <math.h>
using namespace std;

void segmentedBitonicSort(float* data, int* seg_id, int* seg_start, int n, int m) {

    bool asd = true;
    for (int i = 0; i < m; ++i) {
        float *arr = data + seg_start[i]; // �������
        int len = seg_start[i + 1] - seg_start[i]; // ���г���

        // �鲢Ϊ˫������  bitonicMerge(arr, len);
        int merge_len = len;
        for (int merge_step = 2; merge_step < merge_len; merge_step *= 2) {
            for (int merge_i = 0; merge_i < merge_len; merge_i += 2 * merge_step) {
                // merge_stepΪ2����ʱ������벿�ֺ��Ұ벿�ֵĳ���
                int left_len = merge_step, right_len = merge_step;

                // ��벿�ֽ��� bitonicSort(arr + merge_i, left_len, !asd);
                // ������벿�����ݳ���
                if (merge_len - merge_i < merge_step)
                    left_len = merge_len - merge_i;
                // �ҵ����Ĳ�����left_len��p��pΪ2���ݣ�ȷ��sort_step��С
                int left_p = 1;
                while (left_p > 0 && left_p < left_len) left_p <<= 1;
                left_p >>= 1;
                int sort_step = left_p;
                if (sort_step == left_len)
                    sort_step >>= 1;
                // ��벿�ֿ�ͷ
                float* left_arr = arr + merge_i;
                for (; sort_step > 0; sort_step /= 2) {
                    for (int sort_i = 0; sort_i < left_len; sort_i += 2 * sort_step) { // 2 * step һ������
                        for (int j = sort_i; j < sort_i + sort_step && j + sort_step < left_len; ++j) { // ���������ڲ���i���������
                            if (left_arr[j] < left_arr[j + sort_step] || left_arr[j + sort_step] != left_arr[j + sort_step]) {
                                // swap(left_arr[j], left_arr[j + sort_step])
                                float tmp = left_arr[j];
                                left_arr[j] = left_arr[j + sort_step];
                                left_arr[j + sort_step] = tmp;  
                            }
                        }
                    }
                }

                // �Ұ벿���������� bitonicSort(data + merge_step + merge_i, right_len, asd);
                if (left_len == merge_step) { // ��벿�����ݲ��㣬�Ұ벿��Ҳû����
                    // �����Ұ벿�����ݳ���
                    if (merge_len - merge_step - merge_i < merge_step)
                        right_len = merge_len - merge_step - merge_i;
                    // �ҵ����Ĳ�����right_len��p��pΪ2���ݣ�ȷ��sort_step��С
                    int p = 1;
                    while (p > 0 && p < right_len) p <<= 1;
                    p >>= 1;
                    int sort_step = p;
                    if (sort_step == right_len)
                        sort_step >>= 1;
                    // �Ұ벿�ֿ�ͷ
                    float* right_arr = arr + merge_step + merge_i;
                    for (; sort_step > 0; sort_step /= 2) {
                        for (int sort_i = 0; sort_i < right_len; sort_i += 2 * sort_step) { // 2 * step һ������
                            for (int j = sort_i; j < sort_i + sort_step && j + sort_step < right_len; ++j) { // ���������ڲ���i���������
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
        
        // �������� bitonicSort(arr, len, asd);
        int sort_len = len;
        // �ҵ����Ĳ����� sort_len ��p��pΪ2���ݣ�ȷ��sort_step��С
        int sort_p = 1;
        while (sort_p > 0 && sort_p < sort_len) sort_p <<= 1;
        sort_p >>= 1;
        int sort_step = sort_p;
        if (sort_step == sort_len)
            sort_step >>= 1;
        // ����
        for (; sort_step > 0; sort_step /= 2) {
            for (int sort_i = 0; sort_i < sort_len; sort_i += 2 * sort_step) { // 2 * step һ������
                for (int j = sort_i; j < sort_i + sort_step && j + sort_step < sort_len; ++j) { // ���������ڲ���i���������
                    if (arr[j] > arr[j + sort_step] || arr[j] != arr[j]) {
                        // swap(arr[j],arr[j + sort_step])
                        float tmp = arr[j];
                        arr[j] = arr[j + sort_step];
                        arr[j + sort_step] = tmp;
                    }
                }
            }
        }

        // ���
        cout << "�� " << i << ": ";
        for (int k = 0; k < len; k++) {
            cout << arr[k] << " ";
        }
        cout << endl << endl;
    }
}

int main() {
    cout << "=================��������0===========================" << endl;
    float data0[5] = {0.8, 0.2, 
                      0.4, 0.6, 0.5};
    int seg_id0[5] = {0,   0,   1,   1,   1};
    int seg_start0[3] = {0, 2, 5};
    int n0 = 5;
    int m0 = 2;
    segmentedBitonicSort(data0, seg_id0, seg_start0, n0, m0);
    cout << endl;

    cout << "=================��������1===========================" << endl;
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

    cout << "=================��������2===========================" << endl;
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

    cout << "=================��������3===========================" << endl;
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
