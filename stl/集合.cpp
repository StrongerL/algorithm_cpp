#include <iostream>
#include <set>
using namespace std;

struct Node {
  int index;
  int val;

  bool operator<(const Node &node) const {
    return this->index < node.index || (this->index == node.index && this->val < node.val); 
  }
};

struct cmp {
  bool operator()(const Node &n1, const Node &n2) const {
    return n1.val < n2.val || (n1.val == n2.val && n1.index < n2.index);
  }
};

void primitiveType() {
  // ����
  // Ĭ��˳�򣬴�С����
  set<int> s;
  // ָ��˳�򣬴�С����
  set<int, less<int>> s0;
  // ָ��˳�򣬴Ӵ�С
  set<int, greater<int>> s1;

  // ����
  s.insert(1);
  s.insert(4);
  s.insert(3);
  s.insert(2);
  s.insert(5);
  // ����ɹ� res.secondΪ�棬������ָ��Ԫ�����ղ����λ��
  // ����ʧ�� res.secondΪ�٣�������ָ���Ѵ��ڵ�Ԫ�ص�λ��
  pair<set<int>::iterator, bool> res = s.insert(7);
  cout << res.second << endl;
  cout << endl;

  // Ѱ��Ԫ��
  if (s.find(10) == s.end())
    cout << "10����set��" << endl;
  cout << endl;

  // ɾ��Ԫ��
  s.erase(7);
  s.erase(s.begin());

  // �������
  set<int>::iterator it;
  for (it = s.begin(); it != s.end(); it++)
  {
    cout << *it << endl;
  }
  cout << endl;
  // �������
  set<int>::reverse_iterator rit;
  for (rit = s.rbegin(); rit != s.rend(); rit++)
  {
    cout << *rit << endl;
  }
  cout << endl;

  // Ԫ�ظ���
  cout << s.size() << endl;

  // ���
  s.clear();

  // �ж��Ƿ�Ϊ��
  cout << s.empty();
}

void customizeType() {
  // ����struct�е����غ�������
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
    cout << it->index << " " << it->val << endl;
  }
  cout << endl;

  // ���ݴ���struct����
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
    cout << it0->index << " " << it0->val << endl;
  }
}

int main() {
  primitiveType();
  // customizeType();
}
