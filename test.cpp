#include <iostream>
#include <cstring>
using namespace std;

int a[3];

int changeN(int n, int k) {
    int sum = 0;
    while (n){
        sum += n % k;
        n = n / k;
    }
    return sum;
}

int main() {
    // cout << a[1];
    cout << changeN(7, 2);

}
