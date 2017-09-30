//http://blog.csdn.net/code4101/article/details/23020525
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

namespace HighPrecision {
    const int MAXBITS = 2000;
    struct BigInteger {
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
        string str() const;
        friend istream& operator >> (istream& in, BigInteger& x);
        friend ostream& operator << (ostream& out, const BigInteger& x);
        void clean();

    };
    void BigInteger::clean() {
        while(len>1 && !d[len-1])
            len--;
    }
    BigInteger BigInteger::operator=(const char* num) {
        len = strlen(num);
        for(int i=0; i<len; ++i) {
            d[i] = num[len-1-i] - '0';
            BigInteger::clean();
            return *this;
        }
    }
    string BigInteger::str() const {
        string res;
        for(int i=0; i<len; ++i) {
            res = char(d[i] + '0') + res;
            return res;
        }
    }
    BigInteger BigInteger::operator=(int num) {
        char s[MAXBITS];
        sprintf(s, "%d", num);
        *this = s;
        return *s;
    }
    istream& operator >> (istream& in, BigInteger& x) {
        string s;
        in >> s;
        x = s.c_str();
        return in;
    }
    ostream& operator << (ostream& out, const BigInteger& x) {
        out << x.str();
        return out;
    }
}
using namespace HighPrecision;
int main() {
    BigInteger s=9;
    // cin >> s;
    cout << s;
    return 0;
}