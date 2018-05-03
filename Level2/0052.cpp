#include<iostream>
#include<set>
using namespace std;

set<string> res;
    
void solve(string s, string r){
    if(r == ""){
        res.insert(s);
        return;
    }

    solve(s+r[0], r.substr(1));
    solve(s+r[r.length()-1], r.substr(0, r.length()-1));
}

int main(){
    string s;
    cin >> s;
    solve("", s);
    cout << res.size() << endl;
    return 0;
}