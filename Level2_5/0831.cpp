#include<iostream>
#include<list>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    list<ll> l;
    int low = 1, high = n;
    l.push_back(high--);
    while(low <= high){
        if(low <= high) l.push_front(low++);
        if(low <= high) l.push_back(low++);
        if(low <= high) l.push_front(high--);
        if(low <= high) l.push_back(high--);
    }
    auto it = l.begin();
    while(it != l.end()){
        auto nit = it;
        nit++;
        if(nit == l.end())  nit = l.begin();
        ans += (*it) * (*nit);
        it++;
    }
    cout << ans << endl;
    return 0;
}