/*
全排列

注意：输出的顺序并不是字典序

*/

#include <iostream>
#include <cstring>
using namespace std;

char s[10];
int n;

void permutation(int p) {
    // 指针p已经到达最后一位，不需要再交换
    if (p == n - 1) {
        for (int i = 0; i < n; i++) {
            cout << s[i];
        }
        cout << endl;
        return;
    }

    /*
        指针所指的字符分别和自身及之后的所有字符都交换一次，进入下一层调用，
        下一层调用中的指针比当前层要后移一位，每次调用结束后要再交换一次，回归原来的顺序。

        例如123，指针指向1，那么上述过程就是
        1和1交换，交换后为123，调用下一层，下一层中指针指向2，调用结束后，1和1交换回来，交换后为123
        1和2交换，交换后为213，调用下一层，下一层中指针指向1，调用结束后，1和2交换回来，交换后为123
        1和3交换，交换后为321，调用下一层，下一层中指针指向2，调用结束后，1和3交换回来，交换后为123
    */
    for (int i = p; i < n; i++) {
        swap(s[p], s[i]);
        permutation(p + 1);
        swap(s[p], s[i]);
    }

}

int main() {
    while (cin >> s) {
        n = strlen(s);
        permutation(0);
        cout << endl;
    }
}
