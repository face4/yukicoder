#include<iostream>
#include<iomanip>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a = 0, b = 0;
    string s;

    ll base = 10000000000;

    for(int i = 0; i < n; i++){
        cin >> s;

        ll tmpa = 0, tmpb = 0;
        int pos = 0;
        int bias = 1;

        if(s[pos] == '-')   bias = -1, pos++;

        while(pos < s.length() && s[pos] != '.'){
            tmpa = tmpa*10 + s[pos]-'0';
            pos++;
        }
        
        pos++;

        int keta = 0;
        while(pos < s.length()){
            tmpb = tmpb*10 + s[pos]-'0';
            pos++;
            keta++;
        }

        while(keta < 10){
            tmpb *= 10;
            keta++;
        }

        a += tmpa * bias;
        b += tmpb * bias;
    }

    a += b/base;
    if(b < 0)   b -= b/base*base;
    if(b < 0)   b += base, a--;
    b %= base;

    if(a < 0){
        if(b > 0){
            b = base-b;
            a++;
            if(a == 0)  cout << "-";
        }
        b = abs(b);
        cout << a << "." << setw(10) << right << setfill('0') << b << endl;
    }else{
        if(b < 0){
            b += base;
            a--;
        }
        cout << a << "." << setw(10) << right << setfill('0') << b << endl;
    }
    return 0;
}