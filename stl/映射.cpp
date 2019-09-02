/*
map会自动排序

*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node {
  int a;
  string b;
  // 如果键node1 < node2不成立且node2 < node1也不成立，那么map认为node1等于node2
  bool operator<(const Node &node) const {
    return this->a < node.a || (this->a == node.a && this->b < node.b);
  }
};

struct scmp {
  bool operator()(const Node &node1, const Node &node2) const {
    return node1.b < node2.b || (node1.b == node2.b && node1.a < node2.a);
  }
};

bool cmp(Node node1, Node node2) {
  return node1.a < node2.a || (node1.a == node2.a && node1.b > node2.b);
}

void LearnPrimitiveType() {
  // 创建
  map<int, int> m;
  
  // 增
  m[1] = 100;
  m[2] = 200;
  m[3] = 300;
  m[-1] = -1;

  // 删、查
  map<int, int>::iterator f;
  f = m.find(4);
  if (f == m.end()) {
    cout << "不存在键为4的元素。" << endl;
  } else {
    m.erase(f);
    cout << "键为4的键值对已经被删除。" << endl;
  }
  f = m.find(3);
  if (f == m.end()) {
    cout << "不存在键为3的元素。" << endl;
  } else {
    m.erase(f);
    cout << "键为3的键值对已经被删除。" << endl;
  }
  cout << endl;

  // 改
  m[1] = 1;

  // 容量
  cout << m.size() << endl;
  cout << m.empty() << endl;
  cout << endl;

  // 遍历
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " : " << it->second << endl;
  }
  cout << endl;

  // 清空
  m.clear();
  cout << m.size() << endl;

}

void LearnCustomType() {
  // 根据结构体中的重构函数排序
  map<Node, string> m;
  Node n1;
  n1.a = 1;
  n1.b = 'a';
  m[n1] = "111";
  Node n2;
  n2.a = 1;
  n2.b = 'b';
  m[n2] = "222";
  Node n3;
  n3.a = -1;
  n3.b = "c";
  m[n3] = "333";
  for (map<Node, string>::iterator it = m.begin(); it != m.end(); it++) {
    cout << "[" << it->first.a << ", " << it->first.b << "]" << " : " << it->second << endl;
  }
  cout << endl;

  // 根据传入的struct排序
  map<Node, string, scmp> m1(m.begin(), m.end());
  for (map<Node, string>::iterator it = m1.begin(); it != m1.end(); it++) {
    cout << "[" << it->first.a << ", " << it->first.b << "]" << " : " << it->second << endl;
  }
  cout << endl;

  // 根据传入的函数指针排序
  bool(*fn_pt)(Node, Node) = cmp;
  map<Node, string, bool(*)(Node, Node)> m2(fn_pt);
  m2.insert(m1.begin(), m1.end());
  for (map<Node, string>::iterator it = m2.begin(); it != m2.end(); it++) {
    cout << "[" << it->first.a << ", " << it->first.b << "]" << " : " << it->second << endl;
  }
}

int main() {
  // LearnPrimitiveType();
  LearnCustomType();
}
