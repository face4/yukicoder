#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 1<<30;

struct STa{
private:
    int n;
    vector<int> dat;
public:
    STa(vector<int> ini){
        int siz = ini.size();
        n = 1;
        while(n < siz)   n *= 2;
        dat.resize(2*n-1, INF);
        for(int i = 0; i < siz; i++)    dat[n - 1 + i] = ini[i];
        for(int i = n-2; i >= 0; i--)   dat[i] = min(dat[2*i+1], dat[2*i+2]);
    }

    // focus on k-th node, who controls [l, r)
    int query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return INF;
        if(a <= l && r <= b)    return dat[k];

        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return min(lx, rx);
    }
};

struct STb{
private:
    int n;
    vector<int> dat;
public:
    STb(vector<int> ini){
        int siz = ini.size();
        n = 1;
        while(n < siz)   n *= 2;
        dat.resize(2*n-1, 0);
        for(int i = 0; i < siz; i++)    dat[n - 1 + i] = ini[i];
        for(int i = n-2; i >= 0; i--)   dat[i] = max(dat[2*i+1], dat[2*i+2]);
    }

    // focus on k-th node, who controls [l, r)
    int query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return dat[k];

        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return max(lx, rx);
    }
};

bool isK(int a, int b, int c){
    return (b-a)*(b-c) > 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    int ans = -1;
    double e = -1;
    for(int i = 0; i < m; i++){
        vector<int> x(n);
        for(int j = 0; j < n; j++)  cin >> x[j];
        STa mini(x);
        STb maxi(x);
        ll sum = 0;
        for(int k = 0; k < n; k++){
            for(int l = k+1; l < n; l++){
                int tmps = 0, take;
                if(k != 0){
                    if(x[k] < x[l]) take = maxi.query(0, k);
                    else            take = mini.query(0, k);
                    if(isK(take, x[k], x[l]))   tmps = max({tmps, take, x[k], x[l]});
                }
                if(k+1 != l){
                    take = maxi.query(k+1, l);
                    if(isK(x[k], take, x[l]))   tmps = max({tmps, x[k], take, x[l]});
                    take = mini.query(k+1, l);
                    if(isK(x[k], take, x[l]))   tmps = max({tmps, x[k], take, x[l]});
                }
                if(l != n-1){
                    if(x[k] > x[l]) take = maxi.query(l+1, n+1);
                    else            take = mini.query(l+1, n+1);
                    if(isK(x[k], x[l], take))   tmps = max({tmps, x[k], x[l], take});
                }
                sum += tmps;
            }
        }

        double tmpe = (double)sum / n / (n-1); // 本当は*2だが、最大化にしか興味が無いので定数倍は無視
        if(tmpe > e){
            e = tmpe;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}