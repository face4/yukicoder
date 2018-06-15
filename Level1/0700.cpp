#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    bool res = false;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m-3; j++){
            if(s[j]=='L' && s[j+1]=='O' && s[j+2]=='V' && s[j+3]=='E'){
                res = true;
            }
        }
    }

    if(res) cout << "YES" << endl;
    else    cout << "NO" << endl;

    return 0;
}