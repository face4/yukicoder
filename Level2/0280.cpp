// 解説を見てあ、そうじゃんってなった
#include<iostream>
using namespace std;

int main(){
    long long a, b;
    int n;
    cin >> n;
    cin >> a;
    for(int i = 1; i < n; i++)  cin >> b;
    cout << b << "/" << a << endl;
    return 0;
}
/*
typedef long long ll;

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b); 
}

int main(){
    int n;
    ll mother, child;
    cin >> n >> mother >> child;
    ll g = gcd(mother,child);
    ll first = mother;
    ll second = child;

    mother /= g;
    child /= g;

    for(int i = 2; i < n; i++){
        first = second;
        cin >> second;
        g = gcd(first, second);
        mother *= first/g;
        child *= second/g;
        g = gcd(mother,child);
        mother /= g;
        child /= g;
    }

    cout << child << "/" << mother << endl;
    return 0;
}
*/