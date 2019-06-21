/*
ȫ����

https://www.nowcoder.com/practice/5632c23d0d654aecbc9315d1720421c1?tpId=40&tqId=21374&tPage=3&rp=3&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����6655

��Ŀ����
����һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ������������ַ���������ȫ���С� ���Ǽ������Сд��ĸ��'a' < 'b' < ... < 'y' < 'z'�����Ҹ������ַ����е���ĸ�Ѿ����մ�С�����˳�����С�
��������:
����ֻ��һ�У���һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ�������֪�ַ����ĳ�����1��6֮�䡣
�������:
�������ַ������������з�ʽ��ÿ��һ�����С�Ҫ����ĸ��Ƚ�С��������ǰ�档��ĸ�����¶��壺
��֪S = s1s2...sk , T = t1t2...tk����S < T �ȼ��ڣ�����p (1 <= p <= k)��ʹ��
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp������

ÿ���������������Ҫ�����һ���س���
ʾ��1
����
abc
���
abc
acb
bac
bca
cab
cba

ע�⣺ֱ������Ļ��������ֵ���

 */



#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char s[10];
int n;
vector<string> ans;

void permutation(int p) {
    
    if (p == n - 1) {
        ans.push_back(s);
        return;
    }
    
    for (int i = p; i < n; i++) {
        swap(s[i], s[p]);
        permutation(p + 1);
        swap(s[i], s[p]);
    }
    
}

int main() {
    while (cin >> s) {
        ans.clear();
        n = strlen(s);
        permutation(0);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
        cout << endl;
    }
}
