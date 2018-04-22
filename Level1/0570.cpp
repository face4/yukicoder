#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector< pair<int,char> > P(3);
    string s = "ABC";
    int n;
    for(int i = 0; i < 3; i++){
        cin >> n;
        P[i].first = n;
        P[i].second = s[i];
    }

    sort(P.begin(), P.end()); // first(=身長)でソートされるらしい
    reverse(P.begin(), P.end());
    for(int i = 0; i < 3; i++){
        cout << P[i].second << endl;
    }

    return 0;
}