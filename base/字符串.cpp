#include <iostream>
#include <string>
using namespace std;


/*
    ������ͷ�ļ�string���ɿ��ã�Ϊʲô
*/



void testInput() {
    string s;

    // ��ʽ1
    cin >> s;
    cout << s << endl;
    cout << endl;

    // ��ʽ2
    // ���뷽ʽ��������ַ�������ֹ������ֹ�����������s��
    getline(cin, s, '\n'); // �����ϸ��������µĻ��з�
    getline(cin, s, 'a');
    cout << s << endl;
    cout << endl;
}


void testBase() {

    // �ַ�������ʱĬ��Ϊ���ַ���""����������Ч��һ��
    string s;
    string s0 = "";

    // string ������
    string s1 = "123";
    cout << s1[0] << endl;
    cout << s1.at(2) << endl;

    // string ������
    // ����ķ�ʽ
    // string s2 = "123" + "abc";
    // ��ȷ�ķ�ʽ
    string s3 = "123";
    cout << s3 << endl;
    s3 = s3 + "abc";
    cout << s3 << endl;
    s3 += "abc";
    cout << s3 << endl;
    s3 = "abc" + s3;
    cout << s3 << endl;
    cout << endl;

    // string �ıȽ�
    // ���ַ��Ƚϣ�ֱ��������һ�����ַ��Ƚϸ��ַ���
    // ������Ȳ�һ������һ���ַ�������һ����ǰ׺����ô���ĸ���
    // �������һ���ǿ��ַ��������ַ�������
    string s4 = "12534";
    string s5 = "12366";
    cout << (s4 > s5) << endl;
    cout << (s4 < s5) << endl;
    cout << (s4 == s5) << endl;
    cout << endl;

    s4 = "123";
    s5 = "5";
    cout << (s4 > s5) << endl;
    cout << (s4 < s5) << endl;
    cout << (s4 == s5) << endl;
    cout << endl;

    s4 = "123";
    s5 = "12";
    cout << (s4 > s5) << endl;
    cout << (s4 < s5) << endl;
    cout << (s4 == s5) << endl;
    cout << endl;

    s4 = "123";
    s5 = "";
    cout << (s4 > s5) << endl;
    cout << (s4 < s5) << endl;
    cout << (s4 == s5) << endl;
    cout << endl;

}


void testFunctions() {
    string s = "123";

    // �ַ�������
    cout << s.length() << endl;
    cout << s.size() << endl;

    // ����ָ��λ�õ��ַ�
    cout << s.at(0) << endl;





    cout << endl;
}


int main() {

    // testBase();

    // testInput();

    testFunctions();

}
