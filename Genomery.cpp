#include <bits/stdc++.h>
using namespace std;
namespace Genomery2D {
    const double eps = 1e-6;
    struct Point {
        double x, y;
        Point(){}
        Point(double _x, double _y) : x(_x), y(_y) {}

        Point operator -(const Point &a)const {
            return Point(x-a.x, y-a.y);
        }
        Point operator +(const Point &a)const {
            return Point(x+a.x, y+a.y);
        }
        double operator *(const Point &a)const {
            return x*a.x + y*a.y;
        }
        double operator ^(const Point &a)const {
            return x*a.y + y*a.x;
        }
        Point operator +=(const Point &a) {
            *this = *this + a;
            return *this;
        }
        Point operator -=(const Point &a) {
            *this = *this - a;
            return *this;
        }
        friend ostream &operator<<(ostream& os, const Point &a) {
            os << "(" << a.x << ", " << a.y << ")";
            return os;
        }
    };

    struct Vector {
        double x, y;
        Vector() {}
        Vector(double _x, double _y) :  x(_x), y(_y) {}
        Vector(Point s, Point e) : x(e.x-s.x), y(e.y-s.y) {}

        double operator ^(const Vector &a) const {            //向量叉积
            return x*a.y - y*a.x;
        }
    };

    struct Line {
        Point a, b;
        Line() {}
        Line(Point _a, Point _b) : a(_a), b(_b) {}

        friend ostream &operator<<(ostream& os, const Line &a) {
            os << "{(" << a.a.x << ", " << a.a.y << "), ("
                << a.b.x << ", " << a.b.y <<")}" << endl;
            return os;
        }
        double Cross(const Point& p) const {                    //线段与点的位置关系
            Vector tmpa(this->a, this->b);                   //大于0顺时针，小于0逆时针，等于0在线段上
            Vector tmpb(this->a, p);                         //两个向量分别为line::a->line::b & line::a->p
            return tmpb ^ tmpa;
        }
    };
}using namespace Genomery2D;