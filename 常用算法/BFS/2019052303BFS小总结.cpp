/*
bfs�������
�������⣬���ҵ�һ��ͼ�ϵ���ͨ�ĵط��м���
�Թ����⣬��������յ㣬�ʵ����յ������ƶ����������ܻ�Բ������ò�ͬȨֵ�������Ļ�ʹ�����ȶ��м���
�������Σ�ʶ��״̬��ÿ��״̬����������ѡ��ܹؼ�

bfs�������ݽṹ
���д洢������Ҫ���ʵĽڵ�
����洢�Ƿ���ʹ� | Ҳ������map��map�ȿ��Դ洢���ʱ�ʶ�������Դ洢����
״̬���ṹ�壨�Ƚ��������Դ洢������ | pair | ��ϣӳ��


*/
#include <iostream>
#include <queue>
using namespace std;

struct State{
    int i;
    int j;
    int step;

    bool operator < (const State& s) {
        return this -> step > s.step;
    }

};


// ���������ģ
#define maxn 1001
// ����ķ�Χ
int n;
char f[maxn][maxn];
// ���ں���һ��״̬
State cur, post;
// ���ʱ�־
int vis[maxn][maxn];
// ÿ��״̬����������ѡ��
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


// �Ƿ��Ѿ����ʹ����Ƿ�Խ�硢�Ƿ������������
bool check(State s) {

}

// �����������
int bfs(int i, int j) {
    queue<State> q;
    // ÿ���������ĵ�Ȩ�ز�ͬʱҪʹ�����ȶ���
    // priority_queue<State> q;
    cur.i = i;
    cur.j = j;
    q.push(cur);

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        // ���ʹ��������Ҫʹ�����ȶ��У���ôһ��Ҫ�ڳ���ʱ�������ѷ���
        // ������ⲻ��Ҫʹ�����ȶ��У���ô���ʱ�����ѷ���Ҳ����
        vis[cur.i][cur.j] = 1;
        for(int i = 0; i < 4; i++) {
            post.i = cur.i + d[i][0];
            post.j = cur.j + d[i][1];
            if (check(post)) {
                // ����ﵽĿ�꣬���ؽ��
                if (post.i == 0 && post.j == 0)
                    return post.step;
                q.push(post);
            }
        }
    }

    // ������������п���Ҳû�н��������-1��������������ʾĿ�겻�ɴ�
    return -1;

}


int main() {
    
}

