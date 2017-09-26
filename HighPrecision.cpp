//http://blog.csdn.net/code4101/article/details/23020525
#include <iostream>
using namespace std;

namespace HighPrecision {
    struct BigInteger {
        const int MAXBITS = 2000;
        int d[MAXBITS], len;

        BigInteger() {              //初始化，默认初始化为0
            memset(d, 0, sizeof d);
            len = 1;
        }
        BigInteger(int num) {       //初始化，int型
            *this = num;
        }
        BigInteger(char* num) {     //初始化，char型s
            *this = num;
        }

        BigInteger operator = (const char* num);    //赋值，可以用char数组赋值
        BigInteger operator = (int num);
        void clean();
    };
    void BigInteger::clean() {
        while(len>1 && !d[len-1])
            len--;
    }
    BigInteger::operator=(const char* num) {
        len = strlen(num);
        for(int i=0; i<len; ++i) {
            d[i] = num[len-1-i] - '0';
            BigInteger::clean();
            return *this;
        }
    }
}
int main() {

    return 0;
}