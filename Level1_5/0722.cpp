#include<iostream>
using namespace std;

typedef long long ll;

bool check(string x){
    if(x[x.length()-1] != '0' || x[x.length()-2] != '0')    return false;

    if(x[0] == '-') x = x.substr(1);
    for(int i = 1; i < x.length(); i++){
        if(x[i] != '0') return false;
    }

    return true;
}

int main(){
    string a, b;
    cin >> a >> b;

    bool judge = check(a) && check(b);

    ll x = stoll(a);
    ll y = stoll(b);

    if(judge){
        cout << x*y/10 << endl;
    }else{
        ll ans = x*y;
        if(abs(ans) <= 99999999){
            cout << ans << endl;
        }else{
            cout << "E" << endl;
        }
    }
    
    return 0;
}