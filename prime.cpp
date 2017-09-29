
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;


namespace Prime {
    const int M = 99999999;
    bool visit[M];
    int prime[M];

    void table() {
        // memset(visit,true,sizeof(visit));
        // memset(prime, 0, sizeof(prime));
        for(int i=0; i<M; ++i) {
            visit[i] = true;
            prime[i] = 0;
        }
        int num = 0;
        for (int i = 2; i <= M; ++i) {
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
        table();
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

    bool judge_prime(const int x) {
        for(int i=1; i<x; ++i)
            if(prime[i]==x)
                return true;
        return false;
    }
}using namespace Prime;


int main()
{
    print_prime();
    int x;
    while(cin >> x)
        if(judge_prime(x))
            cout << "yes" << endl;
        else cout << "no" << endl;
    return 0;
}
