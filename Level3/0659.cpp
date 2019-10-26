#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

typedef vector<double> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int k = 0; k < B.size(); k++){
            for(int j = 0; j < B[0].size(); j++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

mat pow(mat A, int n){
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i++){
        B[i][i] = 1.0;
    }
    while(n > 0){
        if(n & 1)   B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int h, w, t;
    cin >> h >> w >> t;

    auto f = [=](int i, int j)->int{
        return i*w+j;
    };

    int n = h*w;
    int si, sj, gi, gj;
    cin >> si >> sj >> gi >> gj;

    char x[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> x[i][j];
        }
    }

    mat a(n, vec(n, 0.0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(x[i][j] == '#')  continue;
            int adj = 0;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&x[ni][nj]=='.')  adj++;
            }
            if(adj == 0){
                a[f(i,j)][f(i,j)] = 1.0;
                continue;
            };
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&x[ni][nj]=='.')  a[f(ni,nj)][f(i,j)] = 1.0/adj;
            }
        }
    }
    mat b(n, vec(1,0.0));
    b[f(si,sj)][0] = 1.0;
    a = pow(a, t);
    mat res = mul(a, b);
    cout << fixed << setprecision(12) << res[f(gi,gj)][0] << endl;
    return 0;
}