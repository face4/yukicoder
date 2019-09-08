#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

struct STsum{
    int n;
    vector<ll> dat, youso;

    STsum(int siz){
        n = 1;
        while(n < siz)  n *= 2;
        dat.resize(2*n-1, 0);
        youso.resize(2*n-1, 0);
    }

    void update(int i, ll x){
        i += n-1;
        dat[i] = x;
        youso[i] = 1;
        while(i > 0){
            i = (i-1)/2;
            dat[i] = dat[2*i+1]+dat[2*i+2];
            youso[i] = youso[2*i+1]+youso[2*i+2];
        }
    }

    ll queryS(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return dat[k];
        ll lx = queryS(a, b, 2*k+1, l, (l+r)/2);
        ll rx = queryS(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
    
    int queryN(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return youso[k];
        int lx = queryN(a, b, 2*k+1, l, (l+r)/2);
        int rx = queryN(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<pair<ll,int>> vp;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i], vp.push_back({a[i], i});
    vector<int> l(q), r(q);
    for(int i = 0; i < q; i++){
        int x;
        cin >> l[i] >> l[i] >> r[i] >> x;
        l[i]--, r[i]--;
        vp.push_back({x, i+n});
    }
    sort(vp.rbegin(), vp.rend());
    vector<ll> ans(q);
    STsum seg(n);
    for(int i = 0; i < n+q; i++){
        if(vp[i].second >= n){
            int ind = vp[i].second-n;
            ans[ind] = seg.queryS(l[ind], r[ind]+1)-vp[i].first*seg.queryN(l[ind], r[ind]+1);
        }else{
            seg.update(vp[i].second, vp[i].first);
        }
    }
    for(int i = 0; i < q; i++)  cout << ans[i] << endl;
    return 0;
}