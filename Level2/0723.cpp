#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;

    int a[n];
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[a[i]]++;
    }

    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > x)    continue;

        int target = x-a[i];
        if(m.count(target)) cnt += m[target];
    }

    cout << cnt << endl;

    return 0;
}