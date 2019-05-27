#include <iostream>
using namespace std;

string t(string s) {
    string ss = s;
    ss[0] = '0';
    cout << &ss << endl;;
    return ss;
}

void testEquals() {
    string a = "123";
    string b = "123";
    cout << (a == b) << endl;

    a = "1234";
    cout << (a == b) << endl;
}


int main() {
    // string s = "123";
    // string ss = t(s);
    // cout << ss << endl;
    // cout << &ss << endl;
    // cout << s << endl;
    // testEquals();
    string s = "q122";
    string ss = s;
    ss[0] = 48;
    cout << s << endl;
    cout << ss << endl;



}