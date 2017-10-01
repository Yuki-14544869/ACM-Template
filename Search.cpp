#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

int ans = 0;
int N, K;
char maps[10][10] = {0};

namespace Search2D {
    struct point {
        int x, y;

        point() {}
        point(int _x, int _y):x(_x), y(_y) {}
        friend ostream &operator<<(ostream &os, const point &a) {
            os << a.x << " " << a.y;
            return os;
        }
        point operator+(const point &a) {
            return point(x+a.x, y+a.y);
        }
        point operator-(const point &a) {
            return point(x-a.x, y-a.y);
        }
        point operator+=(const point &a) {
            *this = *this + a;
            return *this;
        }
    };
    //point dis[4] = {(-1,0),(0,-1),(1,0),(0,1)};
    point dis[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool flag[10] = {false};
    bool check(point x) {
        if(x.x<0 || x.x>=N || x.y<0 || x.y>=N)
            return false;
        if(!flag[x.y])
            return false;
        return maps[x.x][x.y] != '#';
    }
    void BFS(point start) {
        queue<point> q;
        q.push(start);

        while(!q.empty()) {
            point now = q.front();
            q.pop();
            ans++;

            for(int i=0; i<4; ++i) {
                point tmp = now;
                tmp += dis[i];
                if(!check(tmp))
                    continue;
                maps[tmp.x][tmp.y] = '#';
                q.push(tmp);
            }
        }
    }
    void DFS(int x, int k) {
        if(k==K) {
            ans++;
            return ;
        }
        if(x > N)
            return ;
        for(int i=0; i<N; ++i) {
            if(maps[x][i]!='#' || flag[i])
                continue;
            flag[i] = true;
            DFS(x+1, k+1);
            flag[i] = false;
        }
        DFS(x+1, k);
        return ;
    }
}using namespace Search2D;
point start;

int main() {
    //freopen("in.txt", "r", stdin);
    while(cin >> N >> K) {
        if(N==-1 && K==-1)
            return 0;
        for(int i=0; i<N; ++i) {
            cin >> maps[i];
        }

        DFS(0, 0);
        cout << ans << endl;

    //   for(int i=0; i<N; ++i) {
    //       cout << maps[i] << endl;
    //   }
    //    cout << endl;

        memset(maps, 0, sizeof maps);
        memset(flag, false, sizeof flag);
        ans = 0;
    }
    return 0;
}