/*
function template
<algorithm>

std::sort
default (1)	
template <class RandomAccessIterator>
void sort (RandomAccessIterator first, RandomAccessIterator last);
custom (2)	
template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);

Sort elements in range
Sorts the elements in the range [first,last) into ascending order.
The elements are compared using operator< for the first version, and comp for the second.
Equivalent elements are not guaranteed to keep their original relative order (see stable_sort).
*/

#include <iostream>
using namespace std;
// sort()ͷ�ļ�
#include <algorithm>

#include <vector>

struct Node{
    int val;
    string name;
};

bool cmp(Node a, Node b) {
    return a.val < b.val;
}

void sort_array() {
     // ���飬������������
    int a[] = {5, 3, 2, 1, 4};
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    sort(a, a + 5); // ��ͬ�� sort(a, a + 5, greater<>()); ����
    // sort(a, a + 5, less<>());  ����
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    // ���飬�Զ�����������
    Node nodes[5];
    nodes[0].val = 5; nodes[0].name = "��";
    nodes[1].val = 3; nodes[1].name = "��";
    nodes[2].val = 2; nodes[2].name = "��";
    nodes[3].val = 1; nodes[3].name = "һ";
    nodes[4].val = 4; nodes[4].name = "��";
    for (int i = 0; i < 5; i++) {
        cout << nodes[i].name << " ";
    }
    cout << endl;
    sort(nodes, nodes + 5, cmp);
    for (int i = 0; i < 5; i++) {
        cout << nodes[i].name << " ";
    }
    cout << endl;
}

void sort_vector() {
    // ����
    int b[] = {5, 3, 2, 1, 4};
    vector<int> v(begin(b), end(b));
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
   sort_array();
   sort_vector();
}
