#include <iostream>
#include <cstring>
using namespace std;

void base() {
    // �Զ���β�����'\0'
    char s1[] = "hello";
    // ��Ҫʹ�����ַ�ʽ��ĩβ�������'\0'��������������
    char s2[] = {'h', 'e', 'l', 'l', 'o'};
    // ����ʹ�����ַ�ʽ
    char s3[] = {'h', 'e', 'l', 'l', 'o', '\0'}; 
    // ����ҪΪĩβ��'\0'����һ��λ��
    char s4[6] = "hello";

    cout << s1 << " " << strlen(s1) << endl;
    cout << s2 << " " << strlen(s2) << endl;
    cout << s3 << " " << strlen(s3) << endl;
    cout << s4 << " " << strlen(s4) << endl;

}


void input() {
    char s[3];
    // ���뷽ʽ1
    // cin.getline(char array[], int size, char delimitChar)������������Ĭ��Ϊ'\n'
    // ֱ��������size - 1���ַ����������ս��ַ�ֹͣ���룬���һ���ַ��������'\0'�ᱻ���滻
    cin.getline(s, 10, '\n');
    cout << s << endl;

    // ���뷽ʽ2�����볤�ȳ�����Χ���Զ�����
    cin >> s;
    cout << s << " " << strlen(s) << endl;
    cout << endl;

}

// ��������֮ǰҪ�Լ���֤�ռ��㹻����Խ��
// ��<cstring>ͷ�ļ���
void functions1() {

    char s1[10] = "123";
    char s2[10] = "136";

    // ����s1����
    cout << strlen(s1) << endl;
    cout << endl;

    // ��s2���Ƶ�s1�У�s1 = "126"�ᱨ��
    strcpy(s1, s2);
    cout << s1 << endl;
    strcpy(s1, "123");
    // ��s2��ǰ2λ���Ƶ�s1��ǰ2λ�����s2�ĵڶ�λ��'\0'��Ҳ�Ḵ��
    strncpy(s1, s2, 2);
    cout << s1 << endl;
    strncpy(s1, "1234", 3);
    cout << endl;

    // ��S2ƴ�ӵ�s1��
    strcat(s1, s2);
    cout << s1 << endl;
    strcpy(s1, "123");
    // ��s2��ǰ2λƴ�ӵ�s1��
    strncat(s1, s2, 2);
    cout << s1 << endl;
    strcpy(s1, "123");
    cout << endl;

    // �Ƚ�s1��s2��s1���ڡ����ڡ�С��s2�ֱ𷵻�������0������
    cout << strcmp(s1, s2) << endl;
    // �Ƚ�s1��ǰ2λ��s2��ǰ2λ��s1��ǰ2λ���ڡ����ڡ�С��s2��ǰ2λ�ֱ𷵻�������0������
    cout << strncmp(s1, s2, 2) << endl;
    cout << endl;

    // ����10����100��16���Ʊ�ʾ����֪��Ϊʲô���ظ�һ�Σ�����
    char s[100];
    cout << itoa(100, s, 10);
    cout << s << endl;
}


void functions2() {

    // �����ַ�����intֵ��ֱ�������������ֵ��ַ����ߵ����ַ���β������һ���ַ��������ַ���0
    char s1[] = "10";
    cout << -1 * atoi(s1) << endl;
    cout << endl;

    // �����ַ�����doubleֵ
    char s2[] = "10.4";
    cout << -1 * atof(s2) << endl;
    cout << endl;

    // �����ַ�����Ӧ��longֵ
    char s3[] = "111";
    cout << -1 * atol(s3) << endl;
    cout << endl;

}


int main() {

    // base();

    // input();

    // functions1();

    functions2();

}