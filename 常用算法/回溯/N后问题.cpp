#include <iostream>
using namespace std;

int chess_board[10][10];
int l[20];
int r[20];
int m[10];
int count;

void nQueen(int n, int p) {
    // 发现解
    if (p == n) {
        count++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << chess_board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // 第p行的每一列
    for (int j = 0; j < n; j++) {
        // 如果满足条件
        if (!l[p + j] && !r[p - j + n - 1] && !m[j]) {
            // 放皇后
            chess_board[p][j] = 1;
            l[p + j] = 1;
            r[p - j + n - 1] = 1;
            m[j] = 1;
            // 继续探索下一行
            nQueen(n, p + 1);
            // 去皇后
            chess_board[p][j] = 0;
            l[p + j] = 0;
            r[p - j + n - 1] = 0;
            m[j] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    nQueen(n, 0);
    cout << count;
}
