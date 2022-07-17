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

void print(Point* p, int n){
    for (int i=0; i<n; i++) {
        cout<<p[i].x<<", "<<p[i].y<<endl;
    }
}

void print(vp::iterator p, int n){
    for (int i=0; i<n; i++) {
        cout<<p[i].x<<", "<<p[i].y<<endl;
    }
}

bool sortx(Point &a, Point &b){
    return a.x<b.x;
}
bool sorty(Point &a, Point &b){
    return a.y<b.y;
}

float cross_closest(Point* py, int n, float d, float xmid, Point &a, Point &b, float &till_now_least){
    //cout<<"entered cross, d and xmid are is "<<d<<" "<<xmid<<"\n";
    float best = d;
    vp sy;
    for (int i=0; i<n; i++) {
        if (py[i].x>=xmid-d && py[i].x<=xmid+d){
            sy.push_back(py[i]);
        }
    }
    int lim1, lim2;
    lim1 = (int) sy.size() > 7 ? sy.size()-7 : sy.size();
    //cout<<"vector sy made of size "<<sy.size()<<"\n";
    //print(sy.begin(), sy.size());
    for (int i=0; i<lim1; i++){
        lim2 = (int) sy.size() > 7 ? 7 : sy.size() - i-1;
        for (int j=1; j<=lim2; j++) {
            if (sy[i].dist(sy[i+j])<best){
                best = sy[i].dist(sy[i+j]);
                if (best<till_now_least){
                    till_now_least = best;
                    a = sy[i]; b = sy[i+j];
                }
            }
        }
    }
    //cout<<"loop run\n";
    return best;
}

float closest(Point* pts, int n, Point &a, Point &b, float &till_now_least) {
    if (n==1){
        //cout<<"single point\n";
        return 99999999;
    }
    if (n==2){
        float distance = pts[0].dist(pts[1]);
        if (distance<till_now_least){
            till_now_least = distance;
            a = pts[0]; b = pts[1];
        }
        return distance;
    }
    Point py[n];
    copy(pts, pts+n, py);
    sort(py, py+n, sorty);
    sort(pts, pts+n, sortx);
    //cout<<"copying and sorting done"<<endl;
    /*
    print(pts, n);
    print(py, n);
    return 0;
    */
    Point q[n/2], r[n-n/2];
    copy(pts, pts+n/2, q);
    copy(pts+n/2, pts+n, r);
    //cout<<"points in q are \n";
    //print(q, n/2);
    //cout<<"points in r are \n";
    //print(r, n-n/2);
    float xmid = pts[n/2].x;
    float d1 = closest(q, n/2, a, b, till_now_least);
    float d2 = closest(r, n-n/2, a, b, till_now_least);
    float d = min(d1, d2);
    float least = min(d, cross_closest(py, n, d, xmid, a, b, till_now_least));
    return least;
}

int main(){
    int n; cin>>n;
    Point points[n];
    for (int i=0; i<n; i++) {
        cin>>points[i].x;
        cin>>points[i].y;
    }
    // cout<<"points taken in"<<endl;
    Point a, b; float temp = 99999;
    cout<<closest(points, n, a, b, temp)<<endl;
    cout<<"between points "<<a.x<<", "<<a.y<<" and "<<b.x<<", "<<b.y<<endl;

}
