#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
#define max 5000000

bool np[max] = {};
vector<int> p;

int main(){
    np[0] = np[1] = true;
    for(int i = 2; i < max; i++){
        if(!np[i]){
            p.push_back(i);
            for(int j = i+i; j < max; j += i)   np[j] = true;
        }
    }

    ll n, l;
    cin >> n >> l;

    ll ans = 0;
    double upper = (double)l/(n-1);

    for(int prime : p){
        if(prime > upper)   break;
        ans += l-(n-1)*prime+1;
    }

    cout << ans << endl;
    return 0;
}