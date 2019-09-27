#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n, d;
    string s;
    cin >> n >> d >> s;
    int i = 0;
    vector<ll> v(d+1, 0);
    int depth = 0;
    while(i < n){
        if(s[i] == 'd'){
            depth++;
            i+=2;
        }else if(s[i] == '+'){
            // do nothing.
            i++;
        }else if(s[i] == '}'){
            depth--;
            i++;
        }else{
            int deg = 0;
            ll num = 1;
            while(i < n && (s[i] == 'x' || isdigit(s[i]))){
                if(isdigit(s[i]))   num *= s[i]-'0';
                else                deg++;
                i++;
                if(i < n && s[i] == '*') i++;
            }
            for(int j = 0; deg > -1 && j < depth; j++){
                num = num*(deg--);
            }
            if(deg >= 0)    v[deg] += num;
        }
    }
    for(int i = 0; i <= d; i++) cout << v[i] << " \n"[i==d];
    return 0;
}
