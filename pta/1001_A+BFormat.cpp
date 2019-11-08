#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, sum;
    string s;
    cin >> a >> b;
    sum = a + b;
    s = to_string(sum);
    for (int i = s.length() - 3; i >= 1; i = i - 3) {
        s.insert(i, ",");
    }
    if (s.length() > 1 && s[0] == '-' && s[1] == ',') {
        s.erase(1, 1);
    }
    cout << s;

    return 0;
}
