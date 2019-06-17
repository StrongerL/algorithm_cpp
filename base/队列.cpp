#include <iostream>
#include <queue>
using namespace std;

// queueʾ���еĽڵ�
class Node {
    public:
        int a;
        string s;
};

// priority_queueʾ���еĽڵ�
struct Node2 {
    int val;
    int index;

    // ���� this < qn �Ķ���
    bool operator < (const Node2& qn) const {
        return this -> val < qn.val;
    }
};

// ���� a < b�Ķ���
struct cmp {
    bool operator () (const Node2& a, const Node2& b) const {
        return a.index < b.index;
    }
};



void learnQueue() {
    /*
        ���ʣ��Ƚ��ȳ�
        ͷ�ļ��� #include <queue>
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
    // emplace ���ڽṹ�塢��ȣ�����ֱ�Ӵ��빹�������Ԫ�أ�emplace�Զ������乹�캯��
    q2.emplace(1, 2);
    cout << q2.front().first << endl;

    // swap���������кʹ������
    queue<int> q3;
    q3.push(233);
    q.swap(q3);
    cout << q.front() << endl;
}


void learnPriorityQueue() {
    /*
        �ο��� https://blog.csdn.net/c20182030/article/details/70757660
        ͷ�ļ��� #include <queue>
        Ĭ������ʽ�� �Ӵ�С
    */

    // ���������������ڵ�
    // Ĭ�ϵ����ȶ��У��Ӵ�С
    priority_queue<int> p1;
    // �Ӵ�С�����ȶ���
    priority_queue<int, vector<int>, less<int> > p2;
    priority_queue<int, vector<int>, greater<int> > p3;

    // �ṹ�����ڵ�
    // �ڽṹ�������� < �����
    priority_queue<Node2> p4;
    // ʹ�������ȽϷ�ʽ
    priority_queue<Node2, vector<Node2>, cmp> p5;

    cout << "priority_queue<int> p1���Ӵ�С" << endl;
    p1.push(1);
    p1.push(5);
    p1.push(3);
    while (!p1.empty()) {
        cout << p1.top() << endl;
        p1.pop();
    }
    cout << endl;

    cout << "priority_queue<int, vector<int>, less<int> > p2�� �Ӵ�С" << endl;
    p2.push(1);
    p2.push(5);
    p2.push(3);
    while (!p2.empty()) {
        cout << p2.top() << endl;
        p2.pop();
    }
    cout << endl;

    cout << "priority_queue<int, vector<int>, greater<int> > p3�� ��С����" << endl;
    p3.push(1);
    p3.push(5);
    p3.push(3);
    while (!p3.empty()) {
        cout << p3.top() << endl;
        p3.pop();
    }
    cout << endl;

    Node2 node;
    cout << "priority_queue<Node2> p4������ < �����������val�Ӵ�С����" << endl;
    node.index = 1;
    node.val = 5;
    p4.push(node);
    node.index = 2;
    node.val = 3;
    p4.push(node);
    node.index = 3;
    node.val = 1;
    p4.push(node);
    while (!p4.empty()) {
        cout << "index : " << p4.top().index << "\tval : " << p4.top().val << endl;
        p4.pop();
    }
    cout << endl;

    cout << "priority_queue<Node2, vector<Node2>, cmp> p5����cmp�ж��� < ��ϵ������index�Ӵ�С����" << endl;
    node.index = 1;
    node.val = 5;
    p5.push(node);
    node.index = 2;
    node.val = 3;
    p5.push(node);
    node.index = 3;
    node.val = 1;
    p5.push(node);
    while (!p5.empty()) {
        cout << "index : " << p5.top().index << "\tval : " << p5.top().val << endl;
        p5.pop();
    }
    cout << endl;

}



int main() {

    // ����
    // learnQueue();

    // ���ȶ���
    learnPriorityQueue();

}