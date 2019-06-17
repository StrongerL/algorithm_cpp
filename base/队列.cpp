#include <iostream>
#include <queue>
using namespace std;

// queue示例中的节点
class Node {
    public:
        int a;
        string s;
};

// priority_queue示例中的节点
struct Node2 {
    int val;
    int index;

    // 重载 this < qn 的定义
    bool operator < (const Node2& qn) const {
        return this -> val < qn.val;
    }
};

// 重载 a < b的定义
struct cmp {
    bool operator () (const Node2& a, const Node2& b) const {
        return a.index < b.index;
    }
};



void learnQueue() {
    /*
        性质：先进先出
        头文件： #include <queue>
    */

    // 创建
    queue<int> q; // 普通数据类型
    queue< pair<int, int> > q2; // 结构体、类等

    // 插入值
    q.push(0);
    q.push(10);
    q.push(5);

    // 返回元素个数
    cout << "q的元素个数：" << q.size() << endl;

    // 返回q是否为空，为空返回true
    cout << "q是否为空：" << q.empty() << endl;

    // 返回队头元素
    cout << "q的队头元素" << q.front() << endl;

    // 返回队尾元素
    cout << "q的队尾元素" << q.back() << endl;

    // 队头元素出队，返回值为void
    q.pop();


    cout << endl;


    // 不常用
    // emplace 对于结构体、类等，可以直接传入构造所需的元素，emplace自动调用其构造函数
    q2.emplace(1, 2);
    cout << q2.front().first << endl;

    // swap交换本队列和传入队列
    queue<int> q3;
    q3.push(233);
    q.swap(q3);
    cout << q.front() << endl;
}


void learnPriorityQueue() {
    /*
        参考： https://blog.csdn.net/c20182030/article/details/70757660
        头文件： #include <queue>
        默认排序方式： 从大到小
    */

    // 基本数据类型做节点
    // 默认的优先队列，从大到小
    priority_queue<int> p1;
    // 从大到小的优先队列
    priority_queue<int, vector<int>, less<int> > p2;
    priority_queue<int, vector<int>, greater<int> > p3;

    // 结构体做节点
    // 在结构体中重载 < 运算符
    priority_queue<Node2> p4;
    // 使用其他比较方式
    priority_queue<Node2, vector<Node2>, cmp> p5;

    cout << "priority_queue<int> p1，从大到小" << endl;
    p1.push(1);
    p1.push(5);
    p1.push(3);
    while (!p1.empty()) {
        cout << p1.top() << endl;
        p1.pop();
    }
    cout << endl;

    cout << "priority_queue<int, vector<int>, less<int> > p2， 从大到小" << endl;
    p2.push(1);
    p2.push(5);
    p2.push(3);
    while (!p2.empty()) {
        cout << p2.top() << endl;
        p2.pop();
    }
    cout << endl;

    cout << "priority_queue<int, vector<int>, greater<int> > p3， 从小到大" << endl;
    p3.push(1);
    p3.push(5);
    p3.push(3);
    while (!p3.empty()) {
        cout << p3.top() << endl;
        p3.pop();
    }
    cout << endl;

    Node2 node;
    cout << "priority_queue<Node2> p4，重载 < 运算符，按照val从大到小排序" << endl;
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

    cout << "priority_queue<Node2, vector<Node2>, cmp> p5，在cmp中定义 < 关系，按照index从大到小排序" << endl;
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

    // 队列
    // learnQueue();

    // 优先队列
    learnPriorityQueue();

}