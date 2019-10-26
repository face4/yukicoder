#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0, one = 0, nine = 0;
    for(char c : s){
        if(c == '1'){
            one++;
        }else if(c == '9'){
            if(one){
                one--;
                ans++;
            }else{
                nine++;
            }
        }else{
            ans++;
        }
    }
    ans += min(nine/2, one) + (one-min(nine/2,one))/2;
    cout << ans << endl;
    return 0;
}