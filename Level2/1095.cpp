#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 1<<30;
    set<int> a, b;
    int v[n];
    for(int i = 0; i < n; i++)  cin >> v[i], (i ? b : a).insert(v[i]);
    for(int i = 1; i+1 < n; i++){
        b.erase(v[i]);
        auto x = a.lower_bound(v[i]);
        auto y = b.lower_bound(v[i]);
        if(x != a.end() && y != b.end()){
            ans = min(ans, v[i]+(*x)+(*y));
        }
        if(*a.begin() < v[i] && *b.begin() < v[i]){
            ans = min(ans, v[i]+*a.begin()+*b.begin());
        }
        a.insert(v[i]);
    }
    cout << (ans==1<<30 ? -1 : ans) << endl;
    return 0;
}