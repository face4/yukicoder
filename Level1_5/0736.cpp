#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;

    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    ll g = v[0];
    for(int i = 1; i < n; i++)  g = gcd(g, v[i]);

    for(int i = 0; i < n; i++)  v[i] /= g;

    cout << v[0];
    for(int i = 1; i < n; i++){
        cout << ":" << v[i];
    }
    cout << endl;
    
    return 0;
}