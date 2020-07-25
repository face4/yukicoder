#include<iostream>
#include<vector>
using namespace std;

struct BIT{
    vector<int> v;
    int n;

    BIT(int _n) : n(_n){
        v.resize(n+1, 0);
    }

    void add(int i, int x){
        while(i <= n){
            v[i] += x;
            i += i&-i;
        }
    }

    int sum(int i){
        int ret = 0;
        while(i > 0){
            ret += v[i];
            i -= i&-i;
        }
        return ret;
    }
};

typedef long long ll;

int main(){
    int n;
    cin >> n;
    BIT bit(n);
    vector<int> rev(n+1);
    for(int i = 1; i <= n; i++){
        int x;  cin >> x;
        rev[x] = i;
        bit.add(x, 1);  // サボリ
    }
    ll ret = -n;
    for(int i = 1; i <= n; i++){
        int x;  cin >> x;
        ret += bit.sum(rev[x]);
        bit.add(rev[x], -1);
    }
    cout << ret << endl;
    return 0;
}