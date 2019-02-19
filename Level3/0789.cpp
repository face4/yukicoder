#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct ST{
private:
    int n;
    vector<int> node;

public:
    ST(int _n){
        n = 1;
        while(n < _n)   n *= 2;
        node.resize(2*n-1, 0);
    }

    void add(int k, int x){
        k += n-1;
        node[k] += x;
        while(k > 0){
            k = (k-1)/2;
            node[k] += x;
        }
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return node[k];
        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx + rx;
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> v;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
        v.push_back(b[i]);
        if(a[i] == 1)   v.push_back(c[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int siz = v.size();
    ST st(siz);

    auto pos = [&](int val) -> int{
        return lower_bound(v.begin(), v.end(), val)-v.begin();
    };

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            st.add(pos(b[i]), c[i]);
        }else if(a[i] == 1){
            ans += st.query(pos(b[i]), pos(c[i])+1);
        }
    }

    cout << ans << endl;
    
    return 0;
}