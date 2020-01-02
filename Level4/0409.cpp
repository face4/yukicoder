#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

struct line{
    ll a, b;
    bool operator==(const line other)const{
        return a==other.a && b==other.b;
    }
};

ll f(line l, ll x){
    return l.a*x + l.b;
}

const ll INF = 1ll<<55;

struct LiChaoTree{
    int n;
    vector<ll> xs;
    vector<line> v;
    line tmp{0, INF};
    LiChaoTree(vector<ll> x) : xs(x){
        n = 1;
        while(n < xs.size())  n *= 2;
        while(xs.size() < n)    xs.push_back(x.back());
        v.resize(2*n+1, tmp);
    }
    void add_line(line p, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        int m = (l+r)/2;
        if(v[k] == tmp){
            v[k] = p;
            return;
        }
        ll lx = xs[l], mx = xs[m], rx = xs[r-1];
        bool left = f(p,lx) < f(v[k], lx);
        bool mid = f(p,mx) < f(v[k], mx);
        bool right = f(p,rx) < f(v[k], rx);
        if(left == right){
            if(left)    v[k] = p;
            return;
        }
        if(mid){
            swap(v[k], p);
        }
        // v[k]とpが交わっている部分について更新していくと考えるとわかりやすい
        if(left != mid){
            add_line(p, 2*k+1, l, m);
        }else{
            add_line(p, 2*k+2, m, r);
        }
    }
    ll query(int k){
        ll x = xs[k];
        k += n-1;
        ll ret = INF;
        while(true){
            if(!(v[k]==tmp)) ret = min(ret, f(v[k], x));
            if(k==0)    break;
            k = (k-1)/2;
        }
        return ret;
    }
};

int main(){
    ll n, a, b, w;
    cin >> n >> a >> b >> w;
    vector<ll> d(n);
    for(int i = 0; i < n; i++)  cin >> d[i];
    vector<ll> v;
    for(int i = 0; i <= n; i++) v.push_back(i);
    LiChaoTree lct(v);
    vector<ll> dp(n+1, INF);
    dp[0] = 0;
    lct.add_line(line({0,0}));
    for(ll i = 1; i <= n; i++){
        dp[i] = lct.query(i) - a*(i-1) + (i-1)*i/2*b + d[i-1];
        lct.add_line(line({-i*b, dp[i]+a*i+i*(i+1)/2*b}));
    }
    ll ans = 1ll<<60;
    for(int i = 0; i <= n; i++){
        ans = min(ans, w+dp[i]-a*(n-i)+(n-i)*(n-i+1)/2*b);
    }
    cout << ans << endl;
    return 0;
}