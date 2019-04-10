#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<int> l(8000010, 0), r(8000010, 0);

int main(){
    int n;
    ll d;
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            l[i*i+j*j]++;
            r[4000000+i*i-j*j]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < 8000001; i++){
        if(i-d+4000000 > 8000009)  break;
        ans += l[i]*r[i-d+4000000];
    }
    cout << ans << endl;
    return 0;
}