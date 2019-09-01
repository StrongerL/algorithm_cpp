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
  // ����
  // vector<int> v;
  vector<int> v(3, 100); // 3��100

  // ��
  // ���뵽ĩβ
  v.push_back(0);
  v.push_back(1);
  v.push_back(-1);
  // ���뵽v.begin()֮ǰ������2��Ԫ�أ�Ԫ��ֵ��555
  v.insert(v.begin(), 2, 555);

  // ɾ
  // ɾ��ĩβԪ��
  v.pop_back();
  // ɾ���ض�λ��Ԫ��
  v.erase(v.begin() + 1);

  // ��
  cout << v.front() << endl;
  cout << v[1] << endl;
  cout << v.back() << endl;
  cout << endl;

  // ��
  v[0] = -100;

  // ����
  cout << v.empty() << endl;
  cout << v.size() << endl;
  cout << endl;

  // ����
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // ����
  sort(v.begin(), v.end());
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // ���
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
  // ���սṹ���ڵ������������
  sort(v.begin(), v.end());
  for (vector<Node>::iterator it = v.begin(); it < v.end(); it++) {
    cout << it->a << " " << it->b << " " << endl;
  }
  cout << endl;
  // ���մ��������������
  sort(v.begin(), v.end(), cmp);
  for (vector<Node>::iterator it = v.begin(); it < v.end(); it++) {
    cout << it->a << " " << it->b << " " << endl;
  }
}

int main() {
  PrimitiveType();
  CustomType();
}
