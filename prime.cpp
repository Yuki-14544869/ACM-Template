
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;


namespace Prime {
    const int M = 9999;
    bool visit[M];
    int prime[M];

    void table(const int x) {
        // memset(visit,true,sizeof(visit));
        // memset(prime, 0, sizeof(prime));
        for(int i=0; i<=x; ++i) {
            visit[i] = true;
            prime[i] = 0;
        }
        int num = 0;
        for (int i = 2; i <= x; ++i) {
            if (visit[i] == true) {
                num++;
                prime[num] = i;
            }
            for (int j = 1; ((j <= num) && (i * prime[j] <= M));  ++j) {
                visit[i * prime[j]] = false;
                if (i % prime[j] == 0) break; //点睛之笔
            }
        }
    }

    void print_prime() {
        table(M);
        int x;
        int tmp = 0;
        int cnt = 0;
        for(int i=1; i<5761500; ++i) {
            if(prime[i])
                cnt++;
            if(prime[i] > tmp)
                tmp = prime[i];
        }
        cout << tmp << endl ;
        cout << "total : " << cnt << endl;
    }

    void judge_prime(const int x) {
        if(visit[x])
            cout << "true" << endl;
        else cout << "no" << endl;
    }
}using namespace Prime;

int main()
{
    table(999);
    int x;
    while(cin >> x)
        judge_prime(x);
    return 0;
}
