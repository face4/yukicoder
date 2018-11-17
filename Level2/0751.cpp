#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n, m, a;
    ll child = 1, mother = 1;

    cin >> n >> child;
    for(int i = 1; i < n; i++)  cin >> a, mother *= a;
    
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a;
        if(i % 2 == 0)  mother *= a;
        else            child *= a;
    }

    if(mother < 0)  mother *= -1, child *= -1;
    ll g = gcd(abs(child), mother);

    child /= g;
    mother /= g;

    cout << child << " " << mother << endl;

    return 0;
}