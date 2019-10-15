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

// ˫������
void bitonicSort(int *arr, int len, bool asd) { // asd ����
    int p = greatestPowerOfTwoLessThan(len);
    int step = p;
    if (step == len)
        step >>= 1;
    for (; step > 0; step /= 2) {
        for (int i = 0; i < len; i += 2 * step) { // 2 * step һ������
            for (int j = i; j < i + step && j + step < len; ++j) { // ���������ڲ���i���������
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
    auto *arr = new int[len]; // �Զ�ʶ������
    bool asd = true;

    // 1.���������������
    srand((unsigned int) time(nullptr));
    for (int i = 0; i < len; ++i) {
        arr[i] = (int) rand() % 100;
    }
    cout << "��������: ";
    printArr(arr, len);

    // 2.���������������ת����˫������
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
    cout << "˫������: ";
    printArr(arr, len); // ˫������

    // 3.˫�����кϲ���Ϊ��������
    bitonicSort(arr, len, asd);
    cout << "��������: ";
    printArr(arr, len); // ��������
}
