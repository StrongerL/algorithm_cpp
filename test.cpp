#include <iostream>
#include <math.h>
using namespace std;
int e[60];
int g[60];
int j, k;

int eg(int num) {
    int sum = 1;
    for (int i = 2; i < sqrt(num * 1.0); i++) {
        if (num % i == 0) {
            sum += i;
            sum += num / i;
        }
    }

    if (sum == num)
        return 1;
    if (sum > num)
        return -1;
    return 0;
}

int main() {

    for (int i = 2; i <= 60; i++) {
        int tmp = eg(i);
        if (tmp == 1)
            e[j++] = i;
        else if (tmp == -1)
            g[k++] = i;
    }

    // Êä³ö
    cout << "E: ";
    for (int i = 0; i < j; i++) {
        cout << e[i];
        if (i != j - 1)
            cout << " ";
    }
    cout << endl;
    cout << "G: ";
    for (int i = 0; i < k; i++) {
        cout << g[i];
        if (i != k - 1)
            cout << " ";
    }
}
