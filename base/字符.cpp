/**
 * ASCII��American Standard Code for Information Interchange��������Ϣ������׼���룩��һ��8λ�ı��뷽������ʾ���еĴ�Сд��ĸ�����֡������źͿ����ַ���Ŀǰ��������128���ַ���0 - 127��128����׼ASCII�룬128 - 255����չ�ַ���������������ʹ��ASCII����Ϊ�ַ��ı��뷽����
 * ���õ�ASCII��
 * '0' - '9'    48 - 57
 * 'A' - 'Z'    65 - 90
 * 'a' - 'z'    97 - 122
 * 
 * ���õ�ת���ַ�
 * '\n'     ���з�
 * '\r'     �س���
 * '\t'     �Ʊ��
 * '\"'     ˫����
 * '\\'     ��б��
 * 
 */

#include <iostream>
using namespace std;

// �ַ��Ļ�������
void testBase() {
 
    cout << "�ַ��ĸ�ֵ����ʹ�õ����Ű����ַ�������ֱ��ʹ���������߸��������������Զ���ȡΪ��������" << endl;
    cout << "���ʹ����������ô�ַ���ֵΪ������Ӧ��ASCII�ַ������������ֵ������8λ��2���ƣ�����ô��ȡ��8λ" << endl;
    // ���ʣ������8λ��ֵ������127�أ�
    // �ش�127 - 255�Ĳ�������չASCII�ַ���
    char c = 'a';
    cout << c << endl;
    c = 122;
    cout << c << endl;
    c = 97.6;
    cout << c << endl;
    c = 0xff61; // 16���ƣ��Ͱ�λΪ0x61��Ҳ����10���Ƶ�97����Ӧ'a'
    cout << c << endl;
    cout << endl;

    cout << "�ַ����������Լ���ת�������ڵ���ĸ" << endl;
    char c0 = 'b';
    cout << ++c0 << endl;
    cout << --c0 << endl;
    cout << endl;

    cout << "�ַ�֮������㣬���Զ�ת���ַ���Ӧ��ASCII��ֵ֮�������" << endl;
    char c1 = 'a';
    char c2 = 'b';
    cout << (c1 > c2) << endl;
    cout << (c1 == c2) << endl;
    cout << (c1 < c2) << endl;
    cout << (c1 - c2) << endl;
    cout << (c1 + c2) << endl;
    cout << (c1 * c2) << endl;
    cout << endl;

    cout << "�ַ�����ֵ֮������㣬�Զ�ת�����ַ���Ӧ��ASCII��ֵ����ֵ֮�������" << endl;
    char c3 = 'a' + 2; // ����ת��Ϊ 97 + 2��Ȼ��c3 = 97
    cout << c3 << endl;
    int i = 'a' + 2;
    cout << i << endl;
    double d = 'a' + 0.5;
    cout << d << endl;
    cout << endl;

}

// �����ַ��ĺ���
void testFunction() {
    // ��Ҫͷ�ļ�<cctype>
    char c = 'c';
    char C = 'C';
    char i = '1';
    char b = ' ';

    cout << "isdigit(char c) �ж��Ƿ�Ϊ����" << endl;
    cout << isdigit(c) << endl;
    cout << isdigit(C) << endl;
    cout << isdigit(i) << endl;
    cout << isdigit(b) << endl;
    cout << endl;

    cout << "isalpha(char c) �ж��Ƿ�Ϊ��ĸ" << endl;
    cout << isalpha(c) << endl;
    cout << isalpha(C) << endl;
    cout << isalpha(i) << endl;
    cout << isalpha(b) << endl;
    cout << endl;

    cout << "isalnum(char c) �ж��Ƿ�Ϊ��ĸ��������" << endl;
    cout << isalnum(c) << endl;
    cout << isalnum(C) << endl;
    cout << isalnum(i) << endl;
    cout << isalnum(b) << endl;
    cout << endl;

    cout << "islower(char c) �ж��Ƿ�ΪСд��ĸ" << endl;
    cout << islower(c) << endl;
    cout << islower(C) << endl;
    cout << islower(i) << endl;
    cout << islower(b) << endl;
    cout << endl;

    cout << "isupper(char c) �ж��Ƿ�Ϊ��д��ĸ" << endl;
    cout << isupper(c) << endl;
    cout << isupper(C) << endl;
    cout << isupper(i) << endl;
    cout << isupper(b) << endl;
    cout << endl;

    cout << "isblank(char c) �ж��Ƿ�Ϊ��" << endl;
    cout << isblank(c) << endl;
    cout << isblank(C) << endl;
    cout << isblank(i) << endl;
    cout << isblank(b) << endl;
    cout << endl; 

    cout << "tolower(char c) �����ַ���Сд��ʽ��Ӧ��ASCII��ֵ������ĸ���ַ�������ASCII��ֵ" << endl;
    cout << tolower(c) << endl;
    cout << tolower(C) << endl;
    cout << tolower(i) << endl;
    cout << tolower(b) << endl;
    cout << endl;

    cout << "toupper(char c) �����ַ��Ĵ�д��ʽ��Ӧ��ASCII��ֵ������ĸ���ַ�������ASCII��ֵ" << endl;
    cout << toupper(c) << endl;
    cout << toupper(C) << endl;
    cout << toupper(i) << endl;
    cout << toupper(b) << endl;
    cout << endl;

    cout << "iscntrl(char c) �ж��Ƿ�Ϊ�����ַ��������ַ��ǲ�ռ����ʾ���ϵĴ�ӡλ�õ��ַ�����ASCII����0x00��NUL����0x1f��US��֮����ַ�����0x7f��DEL��" << endl << endl;

    cout << "isprint(char c) �ж��Ƿ�Ϊ�ɴ�ӡ�ַ�����ӡ�ַ������д���0x1f��US����ASCII�룬��0x7f��DEL�����⡣" << endl << endl;

    cout << "isgraph(char c) �ж��Ƿ�Ϊ���˿ո�' '֮��Ŀɴ�ӡ�ַ�" << endl << endl;

    cout << "ispunct(char c) �ж��Ƿ�Ϊ������" << endl << endl;
    
    cout << "isspace(char c) �ж��Ƿ�Ϊ���ַ�" << endl << endl;

    cout << "isxdigit(char c) �ж��Ƿ�Ϊ16�������֣�����0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F" << endl << endl;

}


int main() {

    // �ַ��Ļ�������
    // testBase();

    // �����ַ��ĺ���
    testFunction();

}
