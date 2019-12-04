#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<string> ng;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        string x;
        cin >> x >> v[i];
        ng.insert(x);
    }
    for(string s : v)   if(ng.count(s)==0)   cout << s << endl, ng.insert(s);
    return 0;
}