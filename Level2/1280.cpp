#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    ll c;
    cin >> n >> m >> c;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < m; i++)  cin >> b[i];
    sort(b.begin(), b.end());
    double d = 0;
    for(int i = 0; i < n; i++){
        d += 1.0/n * (b.end()-lower_bound(b.begin(),b.end(),c/a[i]+1))/m;
    }
    cout << fixed << setprecision(12) << d << endl;
    return 0;
}