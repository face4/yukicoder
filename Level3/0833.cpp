#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

struct BIT{
    int n;
    vector<ll> v;

    BIT(int x) : n(x){
        v.resize(n+1, 0);
    }

    void add(int x, int val){
        while(x <= n){
            v[x] += val;
            x += x&-x;
        }
    }

    ll query(int x){
        ll ret = 0;
        while(x > 0){
            ret += v[x];
            x -= x&-x;
        }
        return ret;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    BIT bit(n);
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        bit.add(i+1, x);
    }
    set<int> fr;
    for(int i = 1; i <= n+1; i++) fr.insert(i);
    while(q-- > 0){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            if(fr.count(b+1)){
                fr.erase(b+1);
            }
        }else if(a == 2){
            if(fr.count(b+1)==0){
                fr.insert(b+1);
            }
        }else if(a == 3){
            bit.add(b, 1);
        }else if(a == 4){
            cout << bit.query(*(fr.upper_bound(b))-1) - bit.query(*(--fr.upper_bound(b))-1) << endl;
        }
    }
    return 0;
}