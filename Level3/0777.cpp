#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool comp(pair<pii,int> a, pair<pii,int> b){
    if(a.first.first != b.first.first)  return a.first.first < b.first.first;
    if(a.first.second != b.first.second)    return a.first.second > b.first.second;
    return a.second < b.second;
}

struct ST{
private:
    int n;
    vector<ll> node;
public:
    ST(int siz){
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, 0);
    }

    void assign(int i, ll x){
        i += n-1;
        if(node[i] >= x)    return;
        node[i] = x;
        while(i > 0){
            i = (i-1)/2;
            node[i] = max(node[2*i+1], node[2*i+2]);
        }
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return node[k];
        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return max(lx, rx);
    }
};

int main(){
    int n, a, b, c;
    vector<pair<pii, int>> v;
    vector<int> w;
    w.push_back(0), w.push_back(1000000001); // sentinel
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        v.push_back({{a,b},c});
        w.push_back(b);
    }
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    auto pos = [&](int val)->int{
        return lower_bound(w.begin(), w.end(), val)-w.begin();
    };
    sort(v.begin(), v.end(), comp);
    ST seg(w.size());
    for(int i = 0; i < n; i++){
        seg.assign(pos(v[i].first.second), seg.query(0, pos(v[i].first.second))+v[i].second);
    }

    cout << seg.query(0, w.size()) << endl;

    return 0;
}