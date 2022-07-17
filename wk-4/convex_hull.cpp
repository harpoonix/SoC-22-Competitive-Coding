#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
#include <cmath>
#define vi vector<int>
#define vp vector<Point>
using namespace std;

struct Point {
    float x, y;
    Point():x(0), y(0) {}
    Point(float x, float y) : x(x), y(y){}
    float dist(Point &p){
        return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
    }
};

struct Line {
    // A line from the Point a ---> Point b
    Point *a, *b;
    Line():a(NULL), b(NULL){}
    Line(Point *a, Point *b) : a(a), b(b){}
    float point_distance(Point &p){
        if (a->x == b->x){
            return a->y>b->y ? p.x-a->x : a->x-p.x;
        }
        // Equation of line is y = mx+c where
        float m = (b->y-a->y)/(b->x-a->x);
        float c = b->y-m*b->x;
        float d = (p.y - m*p.x - c)/sqrt(m*m+1);
        return d;
    }
};

bool sortx(Point &a, Point &b){
    return a.x<b.x;
}

Point* find_anticlockwise(Line &l, Point*pts, int n){
    float max = 0; Point *anti = l.b;
    for (int i=0; i<n; i++) {
        if (l.point_distance(pts[i])>max){
            max = l.point_distance(pts[i]);
            anti = pts+i;
        }
    }
    return anti;
}

Point* find_clockwise(Line &l, Point*pts, int n){
    float min = 0; Point *clock = l.b;
    for (int i=0; i<n; i++) {
        if (l.point_distance(pts[i]) < min){
            min = l.point_distance(pts[i]);
            clock = pts+i;
        }
    }
    return clock;
}

void build_left(vp &convex, Point* p, Point *q, Point *pts, int n){
    Line l(p, q);
    Point *left = find_anticlockwise(l, pts, n);
    if (left == l.b){
        return;
    }
    convex.push_back(*left);
    build_left(convex, p, left, pts, n);
    build_left(convex, left, q, pts, n);
}

void build_right(vp &convex, Point* p, Point *q, Point *pts, int n){
    Line l(p, q);
    Point *right = find_clockwise(l, pts, n);
    if (right == l.b){
        return;
    }
    convex.push_back(*right);
    build_right(convex, p, right, pts, n);
    build_right(convex, right, q, pts, n);
}

vp convex_hull (Point* pts, int n) {
    vp convex;
    Point *p=pts, *q=pts;
    for (int i=0; i<n; i++) {
        if (pts[i].x < p->x){
            p=pts+i;
        }
        if (pts[i].x > q->x){
            q = pts+i;
        }
    }
    convex.push_back(*p); convex.push_back(*q);
    /*
    Line l(p, q);
    // Now p is the address of the point which has the least x coordiante of all, and 
    // similarly q is the address of the point with the max x coord
    Point *anti = find_anticlockwise(l, pts, n);
    Point *clock = find_clockwise(l, pts, n);
    convex.push_back(*anti); convex.push_back(*clock);
    */
    build_left(convex, p, q, pts, n);
    build_right(convex, p, q, pts, n);

    return convex;

}

int main(){
    int n; cin>>n;
    Point pts[n];
    for (int i=0; i<n; i++) {
        cin>>pts[i].x; cin>>pts[i].y;
    }
    vp hull = convex_hull(pts, n);
    for (auto p : hull){
        cout<<p.x<<", "<<p.y<<endl;
    }

}
