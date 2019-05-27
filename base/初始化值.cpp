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
    // ʹ��memset����ֵ0����-1����Ҫ<cstring>��
    // void* memset( void* dest, int ch, std::size_t count );
    // dest	-	ָ��Ҫ���Ķ����ָ��
    // ch	-	����ֽ�
    // count	-	Ҫ�����ֽ���
    // �����ֽ��������ǰ����������͵Ĵ�С���������ֽڵķ�ΧΪ0x00-0xff��8��������λΪһ���ֽڣ�
    int nums[5];
    print(nums, 5);
    
    // intΪ�ĸ��ֽ�
    // sizeof(nums) = 4 * 5 = 20
    // 0ʹ��һ���ֽڱ�ʾΪ0x00�����ÿ��intֵ����Ϊ0x00000000��Ҳ��0�������Կ��Ը�0
    memset(nums, 0, sizeof(nums));
    print(nums, 5);
    // -1ʹ��һ���ֽڱ�ʾΪ0x11�����ÿ��intֵ����Ϊ0x11111111��Ҳ��-1�������Կ��Ը�-1
    memset(nums, -1, sizeof(nums));
    print(nums, 5);
    // 1ʹ��һ���ֽڱ�ʾΪ0x01�����ÿ��intֵ����Ϊ0x01010101��10����Ϊ16843009�������Ը�ֵ����1
    memset(nums, 1, sizeof(nums));
    print(nums, 5);
    // ���һ�����Ķ����Ʊ�ʾ����Ҫ<bitset>��
    cout << (bitset<31>)-1 <<endl;
    cout << endl << endl;


    cout << "ȫ�ֱ���Ĭ��Ϊ0���ֲ�����Ĭ��ֵ��ȷ��" << endl;
    int local[5];
    for (int i = 0; i < 5; i++) {
        cout << global[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << local[i] << " ";
    }


}
