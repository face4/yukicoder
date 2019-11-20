#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

void g(ll *x, vector<int> &ans){
    ll det = sqrt(x[1]*x[1]-4*x[0]*x[2]);
    ans.push_back((-x[1]+det)/x[0]/2);
    ans.push_back((-x[1]-det)/x[0]/2);
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    auto f = [=](ll x)->ll{
        return x*x*x+a*x*x+b*x+c;
    };
    vector<int> ans;
    for(int i = 0; i < 1e6; i++){
        if(f(i) == 0){
            ans.push_back(i);
            break;
        }
        if(f(-i)==0){
            ans.push_back(-i);
            break;
        }
    }
    
    // 組み立て除法
    ll x[3];
    x[0] = 1;
    x[1] = a+x[0]*ans[0];
    x[2] = b+x[1]*ans[0];

    g(x, ans);

    sort(ans.begin(), ans.end());
    for(int i = 0; i < 3; i++)  cout << ans[i] << " \n"[i==2];
    
    return 0;
}
