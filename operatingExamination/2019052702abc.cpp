/*
https://www.nowcoder.com/practice/912b15e237ef44148e44018d7b8750b6?tpId=40&tqId=21346&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

abc

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����10613

��Ŀ����
��a��b��c����0��9֮������֣�abc��bcc��������λ�������У�abc+bcc=532������������������a��b��c��ֵ��
��������:
��Ŀû���κ����롣
�������:
���������������Ŀ������a��b��c��ֵ��
a��b��c֮���ÿո������
ÿ�����ռһ�С�

˼·������

*/

#include <iostream>
using namespace std;
int main() {
    for (int a = 1; a < 5; a++) {
        for (int b = 5 - a; b >= 5 - a - 1 && b != 0; b--) {
            int abc = a * 100 + b * 10 + 1;
            int bcc = b * 100 + 1 * 11;
            if (abc + bcc == 532)
                cout << a << " " << b << " " << 1 << endl;
            
            abc = a * 100 + b * 10 + 6;
            bcc = b * 100 + 6 * 11;
            if (abc + bcc == 532)
                cout << a << " " << b << " " << 6 << endl;
        }
    }
}
