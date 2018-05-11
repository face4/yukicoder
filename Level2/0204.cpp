#include<iostream>
using namespace std;

int main(){
    string s,t;
    int n;
    cin >> n >> s >> t;
    s += t;

    string x(n, 'x');
    s = x+s+x;

    int ans = 0;
    for(int i = 0; i < s.size()-n+1; i++){
        t = s;
        if(n != 0){
            for(int j = i; j < i+n; j++){
                if(t[j] == 'o') break;
                t[j] = 'o';
            }
        }
        
        
        int pos = 0;
        while(pos != s.size()){
            while(pos != s.size() && t[pos] == 'x')    pos++;
            int now = 0;
            while(pos != s.size() && t[pos] == 'o'){
                pos++;
                now++;
            }
            ans = max(ans, now);
        }
    }

    cout << ans << endl;
    return 0;
}