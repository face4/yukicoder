#include<iostream>
using namespace std;

int main(){
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    int fa = 0, fb = 0, sa = 0, sb = 0;
    
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') fa++;
        if(s[i] == 'B') fb++;
    }

    for(int i = 0; i < m; i++){
        if(t[i] == 'A') sa++;
        if(t[i] == 'B') sb++;
    }

    cout << min(fa,sa) + min(fb,sb) << endl;

    return 0;
}