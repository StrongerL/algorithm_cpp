/*

https://www.nowcoder.com/practice/136de4a719954361a8e9e41c8c4ad855?tpId=40&tqId=21364&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

���뷭��

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����7516

��Ŀ����
���鱨���ݹ����У�Ϊ�˷�ֹ�鱨���ػ�������Ҫ���鱨��һ���ķ�ʽ���ܣ��򵥵ļ����㷨��Ȼ��������ȫ�����鱨�����룬����Ȼ�ܷ�ֹ�鱨�����׵�ʶ�����Ǹ���һ�����ĵļ��ܷ������Ը�����һ���ַ����������д�a-y,A-Y����ĸ��������ĸ�������z��Z��a��A�������ɵõ�һ���򵥵ļ����ַ�����
��������:
��ȡ��һ���ַ�����ÿ���ַ�������С��80���ַ�
�������:
����ÿ�����ݣ����ÿ���ַ����ļ����ַ�����
ʾ��1
����
Hello! How are you!
���
Ifmmp! Ipx bsf zpv!

*/

#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char s[90];
    // �����пո����ֱ��ʹ��cin�����ܽ�һ��ȫ������
    while (gets(s)) {
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == 'z') {
                s[i] = 'a';
            } else if (s[i] == 'Z') {
                s[i] = 'A';
            } else if (s[i] >= 'a' && s[i] < 'z' || s[i] >= 'A' && s[i] < 'Z'){
                s[i]++;
            }
        }
        cout << s << endl;
    }
}
