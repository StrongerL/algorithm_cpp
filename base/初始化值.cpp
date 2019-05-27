#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

int global[5];

void print(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " "; 
    }
    cout << endl;
}

int main() {
    // 使用memset赋初值0或者-1，需要<cstring>库
    // void* memset( void* dest, int ch, std::size_t count );
    // dest	-	指向要填充的对象的指针
    // ch	-	填充字节
    // count	-	要填充的字节数
    // 按照字节填充而不是按照数据类型的大小，因此填充字节的范围为0x00-0xff（8个二进制位为一个字节）
    int nums[5];
    print(nums, 5);
    
    // int为四个字节
    // sizeof(nums) = 4 * 5 = 20
    // 0使用一个字节表示为0x00，因此每个int值被置为0x00000000（也是0），所以可以赋0
    memset(nums, 0, sizeof(nums));
    print(nums, 5);
    // -1使用一个字节表示为0x11，因此每个int值被置为0x11111111（也是-1），所以可以赋-1
    memset(nums, -1, sizeof(nums));
    print(nums, 5);
    // 1使用一个字节表示为0x01，因此每个int值被置为0x01010101（10进制为16843009），所以赋值后不是1
    memset(nums, 1, sizeof(nums));
    print(nums, 5);
    // 输出一个数的二进制表示，需要<bitset>库
    cout << (bitset<31>)-1 <<endl;
    cout << endl << endl;


    cout << "全局变量默认为0，局部变量默认值不确定" << endl;
    int local[5];
    for (int i = 0; i < 5; i++) {
        cout << global[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << local[i] << " ";
    }


}
