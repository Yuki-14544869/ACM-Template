#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

namespace Geometry {
    struct Point {
        double x, y;

        Point(){}
        Point(double _x, double _y):x(_x), y(_y) {}
        
        bool operator ==(const Point &a) const;
        bool operator >(const Point &a) const;     //点b在点a右上方
        bool operator <(const Point &a) const;     //点b在点a左下方
        Point operator -(const Point &a) const;
        double operator *(const Point &a) const;
        friend ostream &operator<<(ostream &os, const Point &a);
        friend istream &operator>>(istream &is,Point &a);
    };

    istream & operator>>(istream &is, Point &a) {
        is >> a.x >> a.y;
        return is;
    }
    ostream &operator<<(ostream &os, const Point &a) {
        os << "(" <<a.x << ", " << a.y << ")";
        return os;
    }
    double Point::operator *(const Point &a) const {
        return x*a.x + y*a.y;
    }
    Point Point::operator -(const Point &a) const {
        return Point(x-a.x, y-a.y);
    }
    bool Point::operator <(const Point &a) const {
        if(x<a.x && y<a.y)
            return true;
        else return false;
    }
    bool Point::operator ==(const Point &a) const {
        if(x==a.x && y==a.y)
            return true;
        else return false;
    }
    bool Point::operator >(const Point &a) const {     
        if(x>a.x && y>a.y)
            return true;
        else return false;
    }


    
    struct Line {
        Point start, end;

        Line(){}
        Line(Point _a, Point _b):start(_a), end(_b){}

        double GetLen() {
            Point tmp = this->start - this->end;
            return sqrt(tmp*tmp);
        }
    };
}
using namespace Geometry;

int main() {
    Point a(1.0, 2);
    Point b(55, 45);
    // cout << (a>b) << endl;
    // cout << (a<b) << endl;
    Point c(1.1, 2.1);
    // Point c(a);
    cout << (a==c) << endl;
    cout << c.x << endl;
    Line lin(a, c);
    cout << lin.GetLen() << endl;
    Point k;
    cin >> k;
    cout << k << endl;
    cout << "this is the end.";
    return 0;
}