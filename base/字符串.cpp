#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;


/*
    ������ͷ�ļ�string���ɿ��ã�Ϊʲô��

    http://www.cplusplus.com/reference/string/string/?kw=string
*/

// ���ò���
void common() {
    cout << "==============����==================" << endl;
    cout << "������" << endl;
    string s("123");
    cout << s << endl;

    cout << "ʹ��=��ֵ" << endl;
    string s0 = s;
    cout << s0 << endl;

    cout << endl;


    cout << "===============����====================" << endl;
    cout << "����" << endl;
    cout << s.length() << endl;

    cout << "���" << endl;
    s.clear();

    cout << "�ж��Ƿ�Ϊ��" << endl;
    cout << s.empty() << endl;

    cout << endl;


    cout << "================����Ԫ��================" << endl;
    s = "123";
    cout << "s[0]" << endl;
    cout << s[0] << endl;
    
    cout << "s.at(0)" << endl;
    cout << s.at(0) << endl;

    cout << "s.front()" << endl;
    cout << s.front() << endl;

    cout << "s.back()" << endl;
    cout << s.back() << endl;

    cout << endl;


    cout << "=================�޸�====================" << endl;
    string s1 = s;
    string s2;

    cout << "ʹ��+=" << endl;
    s1 = s;
    s1 += "abc";
    cout << s1 << endl;

    cout << "׷��" << endl;
    s1 = s;
    s1.append("abc");
    cout << s1 << endl;

    cout << "��ֵ" << endl;
    s1 = s;
    s1.assign("abc");
    cout << s1 << endl;

    cout << "����" << endl;
    s1 = s;
    s1.insert(3, "abc"); // ���뵽�±�3֮ǰ
    cout << s1 << endl;

    cout << "ɾ��" << endl;
    s1 = s;
    s1.erase(0, 2); // ���±�0��ʼɾ����λ������0��
    cout << s1 << endl;

    cout << "�滻" << endl;
    s1 = s;
    s1.replace(0, 2, "5"); // ���±�0��ʼ��2λ������0����"5"�滻
    cout << s1 << endl;

    cout << "����" << endl;
    s1 = s;
    s2 = "456";
    s1.swap(s2);
    cout << s1 << " " << s2 << endl;

    cout << endl;


    cout << "=================��������=======================" << endl;
    cout << "����c�ַ���ָ��" << endl;
    char s3[10];
    strcpy(s3, s.c_str());
    cout << s3 << endl;

    cout << "����ֵ��c�ַ���" << endl;
    strcpy(s3, "000");
    // ע�������һ�������ǳ��ȣ��е��
    // size_t copy (char* s, size_t len, size_t pos = 0) const;
    int len = s.copy(s3, 2, 1);
    cout << s3 << endl;

    cout << "��ѯ��1�γ����ַ�����λ��" << endl;
    s2 = "123123";
    // �Ҳ�������string::npos(not a position)
    int index = s2.find("1");
    cout << index << endl;
    
    cout << "��ѯ���1�γ����ַ�����λ��" << endl;
    s2 = "123123";
    index = s2.rfind("1");
    cout << index << endl;

    cout << "��ѯ��1�γ����ַ����е���һ�ַ���λ��" << endl;
    s2 = "123123";
    index = s2.find_first_of("32");
    cout << index << endl;

    cout << "��ѯ���1�γ����ַ����е���һ�ַ���λ��" << endl;
    s2 = "123123";
    index = s2.find_last_of("32");
    cout << index << endl;

    cout << "��ѯ��1��û�г����ַ����е���һ�ַ���λ��" << endl;
    s2 = "123123";
    index = s2.find_first_not_of("12");
    cout << index << endl;

    cout << "��ѯ���1��û�г����ַ����е���һ�ַ���λ��" << endl;
    s2 = "123123";
    index = s2.find_last_not_of("32");
    cout << index << endl;

    cout << "�����Ӵ�" << endl;
    s2 = "123456";
    cout << s2.substr(2, 2) << endl; // ���±�2��ʼ��2λ

    cout << "�Ƚ�" << endl;
    s1 = "45";
    s2 = "123456";
    cout << s2.compare(3, 2, s1) << endl;

}

// ����ֵ���͵�ת��
void stringAndDigit() {

    // ʹ�ú���
    cout << "stringתint" << endl;
    string s = "123";
    int i = stoi(s);
    cout << i << endl;

    cout << "intתstring" << endl;
    i = 111;
    s = to_string(i);
    cout << s << endl;

    cout << "stringתdouble" << endl;
    s = "123.12";
    double d = stod(s);
    cout << d << endl;

    // ����0���������֣���Ҫ��
    cout << "doubleתstring" << endl;
    d = 1.2;
    s = to_string(d);
    cout << s << endl;


    // ʹ��stringstream
    // doubleתstring
    d = 1.2;
    ostringstream os;
    os << d;
    s = os.str();
    cout << s << endl;

    // stringתdouble
    s = "1.2";
    istringstream is(s);
    is >> d;
    cout << d << endl;

}

// �ָ��ַ���
void split() {
    // string s = "123 abc 456";
    string s = "hs_10000_p   2007-01-17 19:22:53,315     253.035(s)";

    char cs[s.length() + 1];
    strcpy(cs, s.c_str());

    char* tmp;
    string si[4];
    int n = 0;
    tmp = strtok(cs, " ");

    while (tmp != NULL) {
        si[n++] = string(tmp);
        tmp = strtok(NULL, " ");
    }

    for (int i = 0; i < n; i++) {
        cout << si[i] << endl;
    }
    cout << s << endl;
}

// ����
void input() {
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

// ����
void base() {

    cout << "�ַ���������" << endl;
    // �ַ�������ʱĬ��Ϊ���ַ���""����������Ч��һ��
    string s;
    string s0 = "";
    // ���ȴ����ַ�����Ȼ��ֵ��s01
    string s01 = "hello";
    // Ч�ʸ���
    string s02("hello");
    cout << endl;

    cout << "ʹ��[]����Ԫ��" << endl;
    string s1 = "123";
    cout << s1[0] << endl;
    cout << s1.at(2) << endl;
    cout << endl;

    cout << "����� +" << endl;
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
    s3 = "abc" + 123;
    cout << s3 << endl;
    cout << endl;

    cout << "�Ƚ������" << endl;
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

// ������
void learnConstructor() {

    /*
        (1) (2)����

        default (1)	
        string();
        copy (2)	
        string (const string& str);
        substring (3)	
        string (const string& str, size_t pos, size_t len = npos);
        from c-string (4)	
        string (const char* s);
        from buffer (5)	
        string (const char* s, size_t n);
        fill (6)	
        string (size_t n, char c);
        range (7)	
        template <class InputIterator>
        string  (InputIterator first, InputIterator last);
        initializer list (8)	
        string (initializer_list<char> il);
        move (9)	
        string (string&& str) noexcept;
    */

    std::string s0 ("Initial string");

    // constructors used in the same order as described above:
    std::string s1;
    std::string s2 (s0);
    std::string s3 (s0, 8, 3);
    std::string s4 ("A character sequence");
    std::string s5 ("Another character sequence", 12);
    std::string s6a (10, 'x');
    std::string s6b (10, 42);      // 42 is the ASCII code for '*'
    std::string s7 (s0.begin(), s0.begin()+7);

    std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
    std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
    std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';
}

// ����� =
void learnOperatorEqual() {
    /*
        string (1)	
        string& operator= (const string& str);
        c-string (2)	
        string& operator= (const char* s);
        character (3)	
        string& operator= (char c);
        initializer list (4)	
        string& operator= (initializer_list<char> il);
        move (5)	
        string& operator= (string&& str) noexcept;
     */

    std::string str1, str2, str3;
    str1 = "Test string: ";   // c-string
    str2 = 'x';               // single character
    str3 = str1 + str2;       // string

    std::cout << str3  << '\n';

}


int main() {

    // common();

    stringAndDigit();

    // split();

    // input();

    // base();

    // learnConstructor();

    // learnOperatorEqual();

}
