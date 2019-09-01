#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int id;
  string name;

  Node() {}

  Node(int id, string name) {
    this->id = id;
    this->name = name;
  }
};

void primitiveType() {
  // 创建
  stack<int> s;

  // 插入
  s.push(1);
  s.push(2);
  s.push(3);

  // 大小
  cout << "栈的大小：" << s.size() << endl;

  // 判空
  while (!s.empty()) {
    // 访问栈顶元素
    cout << s.top() << endl;
    // 弹出栈顶元素
    s.pop();
  }

  // 交换
  stack<int> s1, s2;
  s1.push(1);
  s2.push(1);
  s2.push(1);
  cout << "s1.size() : " << s1.size() << "\ts2.size() : " << s2.size() << endl;
  // 交换方式1
  swap(s1, s2);
  cout << "s1.size() : " << s1.size() << "\ts2.size() : " << s2.size() << endl;
  // 交换方式2
  s1.swap(s2);
  cout << "s1.size() : " << s1.size() << "\ts2.size() : " << s2.size() << endl;
}

void customizeType() {
  stack<Node> s;

  // 可以直接传入结构体构造函数的参数，自动创建并push
  s.emplace(0, "0号节点");

  Node n1;
  n1.id = 1;
  n1.name = "1号节点";
  s.push(n1);

  while (!s.empty())
  {
    cout << s.top().id << " " << s.top().name << endl;
    s.pop();
  }
}

int main() {
  // primitiveType();
  customizeType();
}
