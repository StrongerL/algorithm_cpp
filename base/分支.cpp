#include <iostream>
using namespace std;

// 标准的switch，只执行对应代码
void testSwitch1(int a) {
    switch(a) {
    case 1:
        cout << 1 << endl;
        break;
    case 2:
        cout << 2 << endl;
        break;
    default:
        cout << -1 << endl;
        break;
    }
}

// 不加break语句的switch，从对应情况开始执行直至遇到break才停止
void testSwitch2(int a) {
    switch(a) {
    case 1:
        cout << 1 << endl;
    case 2:
        cout << 2 << endl;
    default:
        cout << -1 << endl;
    }
}

// 不加default语句的switch，输入不在定义范围内的情况什么也不会执行
void testSwitch3(int a) {
    switch(a) {
    case 1:
        cout << 1 << endl;
        break;
    case 2:
        cout << 2 << endl;
        break;
    }
}

void testSwitch() {
    // 标准的switch，只执行对应代码
    testSwitch1(1);
    testSwitch1(2);
    testSwitch1(3);
    cout << endl;

    // 不加break语句的switch，从对应情况开始执行直至遇到break才停止
    testSwitch2(1);
    testSwitch2(2);
    testSwitch2(3);
    cout << endl;

    // 不加default语句的switch，输入不在定义范围内的情况什么也不会执行
    testSwitch3(1);
    testSwitch3(2);
    testSwitch3(3);
    cout << endl;
}

int main() {
    testSwitch();
}
