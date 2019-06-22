#include <iostream>
#include <set>
using namespace std;

struct Node {
    int index;
    int val;

    // 不需要重写==运算符吗？？？set是如何判断两个元素值相等的

    // 按照index排列，index一致，按照val排列
    bool operator < (const Node& node) const { 
        if (index < node.index) {
            return true;
        } else if (index > node.index) {
            return false;
        } else {
            return val < node.val;
        }
    }

};


struct cmp {
    bool operator () (const Node& n1, const Node& n2) const {
        if (n1.val < n2.val) {
            return true;
        } else if (n1.val > n2.val) {
            return false;
        } else {
            return n1.index < n2.index;
        }
    }
};


void primitiveType() {

    // 声明
    // 默认顺序，从小到大
    set<int> s;
    // 指定顺序，从小到大
    set<int, less<int> > s0;
    // 指定顺序，从大到小
    set<int, greater<int> > s1;

    // 插入
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    // 插入成功res.second为真，迭代器指向元素最终插入的位置
    // 插入失败res.second为假，迭代器指向已存在的元素的位置
    pair<set<int>::iterator, bool> res = s.insert(7);
    cout << res.second << endl;
    cout << endl;

    // 寻找元素
    if (s.find(10) == s.end())
        cout << "10不在set中" << endl;
    cout << endl;

    // 删除元素
    s.erase(7);
    s.erase(s.begin());

    // 正序输出
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    // 逆序输出
    set<int>::reverse_iterator rit;
    for (rit = s.rbegin(); rit != s.rend(); rit++) {
        cout << *rit << endl;
    }
    cout << endl;

    // 元素个数
    cout << s.size() << endl;

    // 清空
    s.clear();

    // 判断是否为空
    cout << s.empty();

}


void customizeType() {

    // 重载结构体
    set<Node> s;
    Node node1;
    node1.index = 1;
    node1.val = 3;
    s.insert(node1);

    Node node2;
    node2.index = 3;
    node2.val = 1;
    s.insert(node2);

    Node node3;
    node3.index = 2;
    node3.val = 2;
    s.insert(node3);
    
    Node node4;
    node4.index = 3;
    node4.val = 5;
    s.insert(node4);

    set<Node>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << (*it).index << " " << (*it).val << endl;
    }
    cout << endl;

    // 传入比较条件
    set<Node, cmp> s0;
    Node node10;
    node10.index = 1;
    node10.val = 3;
    s0.insert(node10);

    Node node20;
    node20.index = 3;
    node20.val = 1;
    s0.insert(node20);

    Node node30;
    node30.index = 2;
    node30.val = 2;
    s0.insert(node3);
    
    Node node40;
    node40.index = 3;
    node40.val = 5;
    s0.insert(node40);

    set<Node>::iterator it0;
    for (it0 = s0.begin(); it0 != s0.end(); it0++) {
        cout << (*it0).index << " " << (*it0).val << endl;
    }

}

int main() {

    // primitiveType();

    customizeType();

}

