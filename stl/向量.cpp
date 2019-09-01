#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
  int a;
  string b;
  bool operator < (const Node& node) const {
    return this->a < node.a;
  }
};

bool cmp(const Node& n1, const Node& n2) {
  return n1.b < n2.b;
}

void PrimitiveType() {
  // 创建
  // vector<int> v;
  vector<int> v(3, 100); // 3个100

  // 增
  // 插入到末尾
  v.push_back(0);
  v.push_back(1);
  v.push_back(-1);
  // 插入到v.begin()之前，插入2个元素，元素值是555
  v.insert(v.begin(), 2, 555);

  // 删
  // 删除末尾元素
  v.pop_back();
  // 删除特定位置元素
  v.erase(v.begin() + 1);

  // 查
  cout << v.front() << endl;
  cout << v[1] << endl;
  cout << v.back() << endl;
  cout << endl;

  // 改
  v[0] = -100;

  // 容量
  cout << v.empty() << endl;
  cout << v.size() << endl;
  cout << endl;

  // 遍历
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // 排序
  sort(v.begin(), v.end());
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // 清空
  v.clear();
  cout << v.size() << endl;

}

void CustomType() {
  vector<Node> v;
  Node n1;
  n1.a = 1;
  n1.b = "c";
  v.push_back(n1);
  Node n3;
  n3.a = 3;
  n3.b = "a";
  v.push_back(n3);
  Node n2;
  n2.a = 2;
  n2.b = "b";
  v.push_back(n2);
  
  for (vector<Node>::iterator it = v.begin(); it < v.end(); it++) {
    cout << it->a << " " << it->b << " " << endl;
  }
  cout << endl;
  // 按照结构体内的排序规则排序
  sort(v.begin(), v.end());
  for (vector<Node>::iterator it = v.begin(); it < v.end(); it++) {
    cout << it->a << " " << it->b << " " << endl;
  }
  cout << endl;
  // 按照传入排序规则排序
  sort(v.begin(), v.end(), cmp);
  for (vector<Node>::iterator it = v.begin(); it < v.end(); it++) {
    cout << it->a << " " << it->b << " " << endl;
  }
}

int main() {
  PrimitiveType();
  CustomType();
}
