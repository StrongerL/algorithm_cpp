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
    cout << LONG_LONG_MAX << endl;
}
