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

namespace Search3D {
    struct point {
        int x, y, z;

        point(){}
        point(int _x, int _y, int _z):x(_x),y(_y),z(_z) {}

        friend ostream &operator<<(ostream &os, const point &a) {
            os << "(" << a.x << ", " << a.y << ", " << a.z << ")";
            return os;
        }
        point operator+(const point &a) {
            return point(x+a.x, y+a.y, z+a.z);
        }
        point operator-(const point &a) {
            return point(x-a.x, y-a.y, z-a.z);
        }
        point operator+=(const point &a) {
            *this = *this + a;
            return *this;
        }
    };

    point dis[6] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    point start, terminal;

    int dp[35][35][35];
    bool check(point x){
        if(x.x<0 || x.x>=R || x.y<0 || x.y>=C || x.z<0 || x.z>=L)
            return false;
        return maps[x.x][x.y][x.z] != '#';
    }
    void BFS(point start, point terminal) {
        mm(dp, 0);
        queue<point> q;
        q.push(start);
        maps[start.x][start.y][start.z] = '#';

        while(!q.empty()) {
            point now = q.front();
            q.pop();
            if(now.x==terminal.x && now.y==terminal.y && now.z==terminal.z)
                return;

            for(int i=0; i<6; ++i) {
                point tmp = now;
                tmp += dis[i];
                if(!check(tmp))
                    continue;
                maps[tmp.x][tmp.y][tmp.z] = '#';
                dp[tmp.x][tmp.y][tmp.z] = dp[now.x][now.y][now.z] + 1;
                q.push(tmp);
            }
        }
    }
}using namespace Search3D;
