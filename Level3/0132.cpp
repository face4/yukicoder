#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

struct Point{
    double x, y, z;
    Point operator-(Point o){
        return Point({this->x-o.x, this->y-o.y, this->z-o.z});
    }
    double size(){
        return sqrt(x*x + y*y + z*z);
    }
};

Point cross(Point a, Point b){
    double x, y, z;
    x = a.y*b.z-a.z*b.y;
    y = a.z*b.x-a.x*b.z;
    z = a.x*b.y-a.y*b.x;
    return Point({x, y, z});
}

int main(){
    int n;
    cin >> n;
    double x, y, z;
    cin >> x >> y >> z;
    Point p({x, y, z});
    vector<Point> v;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> z;
        v.push_back(Point({x, y, z}));
    }
    double ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                Point a = v[j]-v[i], b = v[k]-v[i];
                Point c = cross(a, b);
                double d = c.x*(-v[i].x) + c.y*(-v[i].y) + c.z*(-v[i].z);
                ans += abs(c.x*p.x + c.y*p.y + c.z*p.z + d) / c.size();
            }
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}