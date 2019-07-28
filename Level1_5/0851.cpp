#include<iostream>
#include<sstream>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int n;
    scanf("%d\n", &n);
    string s;
    getline(cin, s);
    for(char c : s){
        if(c == ' '){
            cout << "\"assert\"" << endl;
            return 0;
        }
    }
    ll v[3];
    v[0] = stoll(s);
    for(int i = 1; i < 3; i++)  cin >> v[i];
    set<ll> x;
    for(int i = 0; i < 3; i++)  for(int j = i+1; j < 3; j++)    x.insert(v[i]+v[j]);
    auto it = x.end();
    it--;
    it--;
    cout << *it << endl;
    return 0;
}