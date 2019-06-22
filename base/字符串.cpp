#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;


/*
    不包含头文件string依旧可用，为什么？

    http://www.cplusplus.com/reference/string/string/?kw=string
*/

// 常用操作
void common() {
    cout << "==============基础==================" << endl;
    cout << "构造器" << endl;
    string s("123");
    cout << s << endl;

    cout << "使用=赋值" << endl;
    string s0 = s;
    cout << s0 << endl;

    cout << endl;


    cout << "===============容量====================" << endl;
    cout << "长度" << endl;
    cout << s.length() << endl;

    cout << "清空" << endl;
    s.clear();

    cout << "判断是否为空" << endl;
    cout << s.empty() << endl;

    cout << endl;


    cout << "================访问元素================" << endl;
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


    cout << "=================修改====================" << endl;
    string s1 = s;
    string s2;

    cout << "使用+=" << endl;
    s1 = s;
    s1 += "abc";
    cout << s1 << endl;

    cout << "追加" << endl;
    s1 = s;
    s1.append("abc");
    cout << s1 << endl;

    cout << "赋值" << endl;
    s1 = s;
    s1.assign("abc");
    cout << s1 << endl;

    cout << "插入" << endl;
    s1 = s;
    s1.insert(3, "abc"); // 插入到下标3之前
    cout << s1 << endl;

    cout << "删除" << endl;
    s1 = s;
    s1.erase(0, 2); // 从下标0开始删除两位（包括0）
    cout << s1 << endl;

    cout << "替换" << endl;
    s1 = s;
    s1.replace(0, 2, "5"); // 从下标0开始的2位（包括0）由"5"替换
    cout << s1 << endl;

    cout << "交换" << endl;
    s1 = s;
    s2 = "456";
    s1.swap(s2);
    cout << s1 << " " << s2 << endl;

    cout << endl;


    cout << "=================其他操作=======================" << endl;
    cout << "返回c字符串指针" << endl;
    char s3[10];
    strcpy(s3, s.c_str());
    cout << s3 << endl;

    cout << "复制值到c字符串" << endl;
    strcpy(s3, "000");
    // 注意这里第一个整数是长度，有点坑
    // size_t copy (char* s, size_t len, size_t pos = 0) const;
    int len = s.copy(s3, 2, 1);
    cout << s3 << endl;

    cout << "查询第1次出现字符串的位置" << endl;
    s2 = "123123";
    // 找不到返回string::npos(not a position)
    int index = s2.find("1");
    cout << index << endl;
    
    cout << "查询最后1次出现字符串的位置" << endl;
    s2 = "123123";
    index = s2.rfind("1");
    cout << index << endl;

    cout << "查询第1次出现字符串中的任一字符的位置" << endl;
    s2 = "123123";
    index = s2.find_first_of("32");
    cout << index << endl;

    cout << "查询最后1次出现字符串中的任一字符的位置" << endl;
    s2 = "123123";
    index = s2.find_last_of("32");
    cout << index << endl;

    cout << "查询第1次没有出现字符串中的任一字符的位置" << endl;
    s2 = "123123";
    index = s2.find_first_not_of("12");
    cout << index << endl;

    cout << "查询最后1次没有出现字符串中的任一字符的位置" << endl;
    s2 = "123123";
    index = s2.find_last_not_of("32");
    cout << index << endl;

    cout << "返回子串" << endl;
    s2 = "123456";
    cout << s2.substr(2, 2) << endl; // 从下标2开始的2位

    cout << "比较" << endl;
    s1 = "45";
    s2 = "123456";
    cout << s2.compare(3, 2, s1) << endl;

}

// 与数值类型的转换
void stringAndDigit() {

    // 使用函数
    cout << "string转int" << endl;
    string s = "123";
    int i = stoi(s);
    cout << i << endl;

    cout << "int转string" << endl;
    i = 111;
    s = to_string(i);
    cout << s << endl;

    cout << "string转double" << endl;
    s = "123.12";
    double d = stod(s);
    cout << d << endl;

    // 会多出0或者少数字，不要用
    cout << "double转string" << endl;
    d = 1.2;
    s = to_string(d);
    cout << s << endl;


    // 使用stringstream
    // double转string
    d = 1.2;
    ostringstream os;
    os << d;
    s = os.str();
    cout << s << endl;

    // string转double
    s = "1.2";
    istringstream is(s);
    is >> d;
    cout << d << endl;

}

// 分割字符串
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

// 输入
void input() {
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

// 基础
void base() {

    cout << "字符串的声明" << endl;
    // 字符串声明时默认为空字符串""，以下两种效果一样
    string s;
    string s0 = "";
    // 首先创建字符串，然后赋值给s01
    string s01 = "hello";
    // 效率更高
    string s02("hello");
    cout << endl;

    cout << "使用[]访问元素" << endl;
    string s1 = "123";
    cout << s1[0] << endl;
    cout << s1.at(2) << endl;
    cout << endl;

    cout << "运算符 +" << endl;
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
    s3 = "abc" + 123;
    cout << s3 << endl;
    cout << endl;

    cout << "比较运算符" << endl;
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

// 构造器
void learnConstructor() {

    /*
        (1) (2)常用

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

// 运算符 =
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
