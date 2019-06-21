#include <iostream>
#include <string>
using namespace std;


/*
    不包含头文件string依旧可用，为什么
*/



void testInput() {
    string s;

    // 方式1
    cin >> s;
    cout << s << endl;
    cout << endl;

    // 方式2
    // 输入方式，输入的字符串，终止符（终止符不会输入进s）
    getline(cin, s, '\n'); // 吸收上个输入留下的换行符
    getline(cin, s, 'a');
    cout << s << endl;
    cout << endl;
}


void testBase() {

    // 字符串声明时默认为空字符串""，以下两种效果一样
    string s;
    string s0 = "";

    // string 的索引
    string s1 = "123";
    cout << s1[0] << endl;
    cout << s1.at(2) << endl;

    // string 的连接
    // 错误的方式
    // string s2 = "123" + "abc";
    // 正确的方式
    string s3 = "123";
    cout << s3 << endl;
    s3 = s3 + "abc";
    cout << s3 << endl;
    s3 += "abc";
    cout << s3 << endl;
    s3 = "abc" + s3;
    cout << s3 << endl;
    cout << endl;

    // string 的比较
    // 逐字符比较，直到遇到不一样的字符比较该字符，
    // 如果长度不一样并且一个字符串是另一个的前缀，那么长的更大，
    // 如果其中一个是空字符串，空字符串更大。
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

    // 字符串长度
    cout << s.length() << endl;
    cout << s.size() << endl;

    // 返回指定位置的字符
    cout << s.at(0) << endl;





    cout << endl;
}


int main() {

    // testBase();

    // testInput();

    testFunctions();

}
