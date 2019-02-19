#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct BIT{
private:
    vector<int> bit;
    int n;
public:
    BIT(int arg){
        n = arg + 5;
        bit.resize(n, 0);
    }

    void add(int i, int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }

    ll sum(int i){
        ll ret = 0;
        while(i > 0){
            ret += bit[i];
            i -= i & -i;
        }
        return ret;
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)  scanf("%d", v.begin()+i);

    vector<int> cp = v;
    sort(cp.begin(), cp.end());
    vector<int> cp2 = cp;
    cp.erase(unique(cp.begin(), cp.end()), cp.end());

    auto pos = [&](int val) -> int{
        return lower_bound(cp.begin(), cp.end(), val)-cp.begin();
    };

    BIT bit(cp.size());
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += i-bit.sum(pos(v[i])+1);
        bit.add(pos(v[i])+1, 1);
    }

    printf("%lld\n", ans);
    for(int i = 0; i < n-1; i++){
        ans += -(lower_bound(cp2.begin(),cp2.end(),v[i])-cp2.begin()) 
               +(cp2.end()-upper_bound(cp2.begin(),cp2.end(),v[i]));
        printf("%lld\n", ans);
    }

    return 0;
}