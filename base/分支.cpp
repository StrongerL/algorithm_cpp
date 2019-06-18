#include <iostream>
using namespace std;

// ��׼��switch��ִֻ�ж�Ӧ����
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

// ����break����switch���Ӷ�Ӧ�����ʼִ��ֱ������break��ֹͣ
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

// ����default����switch�����벻�ڶ��巶Χ�ڵ����ʲôҲ����ִ��
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
    // ��׼��switch��ִֻ�ж�Ӧ����
    testSwitch1(1);
    testSwitch1(2);
    testSwitch1(3);
    cout << endl;

    // ����break����switch���Ӷ�Ӧ�����ʼִ��ֱ������break��ֹͣ
    testSwitch2(1);
    testSwitch2(2);
    testSwitch2(3);
    cout << endl;

    // ����default����switch�����벻�ڶ��巶Χ�ڵ����ʲôҲ����ִ��
    testSwitch3(1);
    testSwitch3(2);
    testSwitch3(3);
    cout << endl;
}

int main() {
    testSwitch();
}
