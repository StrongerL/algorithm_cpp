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
  // ����
  stack<int> s;

  // ����
  s.push(1);
  s.push(2);
  s.push(3);

  // ��С
  cout << "ջ�Ĵ�С��" << s.size() << endl;

  // �п�
  while (!s.empty()) {
    // ����ջ��Ԫ��
    cout << s.top() << endl;
    // ����ջ��Ԫ��
    s.pop();
  }

  // ����
  stack<int> s1, s2;
  s1.push(1);
  s2.push(1);
  s2.push(1);
  cout << "s1.size() : " << s1.size() << "\ts2.size() : " << s2.size() << endl;
  // ������ʽ1
  swap(s1, s2);
  cout << "s1.size() : " << s1.size() << "\ts2.size() : " << s2.size() << endl;
  // ������ʽ2
  s1.swap(s2);
  cout << "s1.size() : " << s1.size() << "\ts2.size() : " << s2.size() << endl;
}

void customizeType() {
  stack<Node> s;

  // ����ֱ�Ӵ���ṹ�幹�캯���Ĳ������Զ�������push
  s.emplace(0, "0�Žڵ�");

  Node n1;
  n1.id = 1;
  n1.name = "1�Žڵ�";
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
