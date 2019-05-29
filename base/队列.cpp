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
        性质：先进先出
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
    // 对于结构体、类等，可以直接传入构造所需的元素，emplace自动调用其构造函数
    q2.emplace(1, 2);
    cout << q2.front().first << endl;

    // swap交换本队列和传入队列
    queue<int> q3;
    q3.push(233);
    q.swap(q3);
    cout << q.front() << endl;
}


void learnPriorityQueue() {
    


}

int main() {

    // 队列
    learnQueue();

    // 优先队列
    learnPriorityQueue();

}