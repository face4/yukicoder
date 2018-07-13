#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

const double EPS = 1e-9;

struct point{
    double x, y;
    point(){ x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}

    // 不等号のオーバーロード.x座標,y座標で昇順ソート
    bool operator < (const point other) const{
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        else
            return y < other.y;
    }

    // 等号のオーバーロード.
    bool operator == (const point other) const{
        return fabs(x - other.x) < EPS &&
                fabs(y - other.y) < EPS;
    }
};

// ベクトル
struct vec{
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

// 2つのpoint a,b をvec a->b に変換
vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

// vecの外積
double cross(vec v1, vec v2){
    return v1.x * v2.y - v1.y * v2.x;
}

// 2つのpoint間の距離 std::hypotenuse(斜辺)を利用
double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// (未確認)
bool ccw(point p, point q, point r){
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// 3つのpointが単一直線上にあるかどうかの判定
bool collinear(point p, point q, point r){
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// 凸包を求めるのに用いる一連の関数
point pivot(0.0, 0.0);

// Graham's Scanの前準備で必要な,pivotからの偏角でソートするときに必要な比較関数
bool angleCmp(point a, point b){
    // 偏角が同じ(pivot,a,bが単一直線上に乗っている)場合は,pivotからの距離が近い方を優先
    if(collinear(pivot, a, b)){
        return dist(pivot, a) < dist(pivot, b);
    }

    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;

    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

// 与えられた点群から凸包を求める(Graham's Scan)
vector<point> ConvexHull(vector<point> P){
    int i, j, n = (int)P.size();

    // 点群が3つしかない場合,P[0]をPに加える(輪っかのイメージ)
    if(n <= 3){
        if(!(P[0] == P[n-1]))  P.push_back(P[0]);
        return P;
    }

    // pivotを定める.最下,最右の点
    int P0 = 0;
    for(i = 1; i < n; i++){
        if(P[i].y < P[P0].y || 
           (P[i].y == P[P0].y && P[i].x > P[P0].x)){
               P0 = i;
        }
    }

    // P[0]とpivotとして選ばれたP[P0]をスワップ
    point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp;

    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);

    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    
    i = 2;
    while(i < n){
        j = (int)S.size() - 1;

        if(ccw(S[j-1], S[j], P[i]))
            S.push_back(P[i++]);
        else
            S.pop_back();
    }

    return S;
}

int main(){
    vector<point> p;
    int x, y;
    for(int i = 0; i < 5; i++){
        cin >> x >> y;
        p.push_back(point(x,y));
    }

    int i;
    for(i = 0; i < 3; i++){
        if(!collinear(p[i],p[i+1],p[i+2]))  break;
    }

    if(i == 3){
        cout << "NO" << endl;
        return 0;
    }
    
    vector<point> convexhull = ConvexHull(p);

    if(convexhull.size() == 6)  cout << "YES" << endl;
    else                        cout << "NO" << endl;

    return 0;
}