/*
map���Զ�����

*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node {
  int a;
  string b;
  // �����node1 < node2��������node2 < node1Ҳ����������ômap��Ϊnode1����node2
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
  // ����
  map<int, int> m;
  
  // ��
  m[1] = 100;
  m[2] = 200;
  m[3] = 300;
  m[-1] = -1;

  // ɾ����
  map<int, int>::iterator f;
  f = m.find(4);
  if (f == m.end()) {
    cout << "�����ڼ�Ϊ4��Ԫ�ء�" << endl;
  } else {
    m.erase(f);
    cout << "��Ϊ4�ļ�ֵ���Ѿ���ɾ����" << endl;
  }
  f = m.find(3);
  if (f == m.end()) {
    cout << "�����ڼ�Ϊ3��Ԫ�ء�" << endl;
  } else {
    m.erase(f);
    cout << "��Ϊ3�ļ�ֵ���Ѿ���ɾ����" << endl;
  }
  cout << endl;

  // ��
  m[1] = 1;

  // ����
  cout << m.size() << endl;
  cout << m.empty() << endl;
  cout << endl;

  // ����
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " : " << it->second << endl;
  }
  cout << endl;

  // ���
  m.clear();
  cout << m.size() << endl;

}

void LearnCustomType() {
  // ���ݽṹ���е��ع���������
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

  // ���ݴ����struct����
  map<Node, string, scmp> m1(m.begin(), m.end());
  for (map<Node, string>::iterator it = m1.begin(); it != m1.end(); it++) {
    cout << "[" << it->first.a << ", " << it->first.b << "]" << " : " << it->second << endl;
  }
  cout << endl;

  // ���ݴ���ĺ���ָ������
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
