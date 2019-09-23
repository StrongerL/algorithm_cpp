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
