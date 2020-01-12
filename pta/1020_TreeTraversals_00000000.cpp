/*
来源
https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072


题目
1020 Tree Traversals (25分)
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2


思路
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(){};
    Node(int val) {
        this->val = val;
    }
};

int n;
int postorder[40];
int inorder[40];

Node* buildTree(int p, int l, int r) {
    if (l > r) return NULL;

    Node *root = new Node(postorder[p]);
    int i = l;
    while (inorder[i] != postorder[p])  i++;

    root->left = buildTree(p - (r - i) - 1, l, i - 1);
    root->right = buildTree(p - 1, i + 1, r);

    return root;
}

void bfs(Node* root) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    ans.push_back(root->val);
    Node* cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->left != NULL) {
            q.push(cur->left);
            ans.push_back(cur->left->val);
        }
        if (cur->right != NULL) {
            q.push(cur->right);
            ans.push_back(cur->right->val);
        } 
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << " ";
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> postorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    Node* root = buildTree(n - 1, 0, n - 1);

    bfs(root);

    return 0;
}
