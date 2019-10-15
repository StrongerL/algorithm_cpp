#include <iostream>
#include <iomanip>
using namespace std;

void printArr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << arr[i];
    }
    cout << endl << endl;
}

int greatestPowerOfTwoLessThan(int n)
{
    int k = 1;
    while (k > 0 && k < n)
        k <<= 1;
    return k >> 1;
}

// 双调排序
void bitonicSort(int *arr, int len, bool asd) { // asd 升序
    int p = greatestPowerOfTwoLessThan(len);
    int step = p;
    if (step == len)
        step >>= 1;
    for (; step > 0; step /= 2) {
        for (int i = 0; i < len; i += 2 * step) { // 2 * step 一组序列
            for (int j = i; j < i + step && j + step < len; ++j) { // 遍历序列内部，i是序列起点
                if (asd) {
                    if (arr[j] > arr[j + step]) swap(arr[j], arr[j + step]);
                } else {
                    if (arr[j] < arr[j + step]) swap(arr[j], arr[j + step]);
                }
            }
        }
    }
}

int main() {
    int len = 13;
    auto *arr = new int[len]; // 自动识别类型
    bool asd = true;

    // 1.随机生成无序序列
    srand((unsigned int) time(nullptr));
    for (int i = 0; i < len; ++i) {
        arr[i] = (int) rand() % 100;
    }
    cout << "无序序列: ";
    printArr(arr, len);

    // 2.将无序的输入序列转换成双调序列
    for (int step = 2; step < len; step *= 2) {
        for (int i = 0; i < len; i += 2 * step) {
            int left_len = step, right_len = step;
            if (len - i < step)
                left_len = len - i;
            bitonicSort(arr + i, left_len, !asd);
            if (left_len == step) {
                if (len - step - i < step)
                    right_len = len - step - i;
                bitonicSort(arr + step + i, right_len, asd);
            }
        }
    }
    cout << "双调序列: ";
    printArr(arr, len); // 双调序列

    // 3.双调序列合并成为有序序列
    bitonicSort(arr, len, asd);
    cout << "有序序列: ";
    printArr(arr, len); // 有序序列
}
