#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int a;
        string s;
};



void learnQueue() {
    /*
        ���ʣ��Ƚ��ȳ�
    */

    // ����
    queue<int> q; // ��ͨ��������
    queue< pair<int, int> > q2; // �ṹ�塢���

    // ����ֵ
    q.push(0);
    q.push(10);
    q.push(5);

    // ����Ԫ�ظ���
    cout << "q��Ԫ�ظ�����" << q.size() << endl;

    // ����q�Ƿ�Ϊ�գ�Ϊ�շ���true
    cout << "q�Ƿ�Ϊ�գ�" << q.empty() << endl;

    // ���ض�ͷԪ��
    cout << "q�Ķ�ͷԪ��" << q.front() << endl;

    // ���ض�βԪ��
    cout << "q�Ķ�βԪ��" << q.back() << endl;

    // ��ͷԪ�س��ӣ�����ֵΪvoid
    q.pop();


    cout << endl;


    // ������
    // ���ڽṹ�塢��ȣ�����ֱ�Ӵ��빹�������Ԫ�أ�emplace�Զ������乹�캯��
    q2.emplace(1, 2);
    cout << q2.front().first << endl;

    // swap���������кʹ������
    queue<int> q3;
    q3.push(233);
    q.swap(q3);
    cout << q.front() << endl;
}


void learnPriorityQueue() {
    


}

int main() {

    // ����
    learnQueue();

    // ���ȶ���
    learnPriorityQueue();

}