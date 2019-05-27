/*
https://www.nowcoder.com/practice/761fc1e2f03742c2aa929c19ba96dbb0?tpId=40&tqId=21343&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking


ʱ�����ƣ�1�� �ռ����ƣ�65536K �ȶ�ָ����5416

��Ŀ����
��������һ�����룬����ַ����г���������2012�ĸ����־��ܽ⿪���롣��һ������ΪN���ַ�������2=<N<=13�����ַ�����ֻ����0,1,2�������֣�������ַ���Ҫ��λ���β��ܽ⿪���룬ÿ��ֻ���ƶ����ڵ��������֡�����02120����һ����λ�����Եõ�20120,01220,02210,02102������20120����Ҫ��������Ϊ1.���������λ���ٴζ��ⲻ�����룬���-1��
��������:
�����������������ݣ�ÿ�����������������ɡ�
��һ��Ϊһ������N�������ַ����ĳ��ȣ�2<=N<=13����
�ڶ���Ϊһ������0��1��2��ɵģ�����ΪN���ַ�����
�������:
����ÿ��������ݣ������Խ�����룬������ٵ���λ�������������-1��
ʾ��1
����
5
02120
���
1



˼·��bfs��ÿ��ѡ��Ϊÿһλ���ƶ�һ��
    ÿ���ַ�������һ���ڵ�

*/


#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

// �����ַ������Ƿ���2012
bool validate(string s) {
    return s.find("2012") != string::npos;
}

// ����i��i+1λ�õ��ַ�
string swap(string s, int i) {
    string tmp = s;
    char t = tmp[i];
    tmp[i] = tmp[i + 1];
    tmp[i + 1] = t;
    return tmp;
}

// ��������������ڵ���һ���ַ���
int bfs(string s) {
    // ��¼��������
    map<string, int> m;
    // �洢��Ҫ�����������ַ���
    queue<string> q;
    q.push(s);
    m[s] = 0;
    string tmp;
    while (!q.empty()) {
        s = q.front();
        q.pop();
        // �ַ���s����һ���ܵ�������п��ܽڵ�
        for (int i = 0; i < s.size() - 1; i++) {
            tmp = swap(s, i);
            // ����ַ������³��ֵ�
            if (m.find(tmp) == m.end()) {
                // ����2012
                if (validate(tmp))
                    return m[s] + 1;
                // ����2012���������м�������
                else {
                    m[tmp] = m[s] + 1;
                    q.push(tmp);
                }
            } 
        }
    }
    return -1;
}

int main() {
    int N;
    string s;
    while (cin >> N >> s) {
        if (N < 4) {
            cout << -1 << endl;
            continue;
        }
        if (validate(s))
            cout << 0 << endl;
        else
            cout << bfs(s) << endl;
    }
}
