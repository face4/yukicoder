#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    char c;
    int plus = 0, minus = 0;
    vector<int> v;

    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == '+')    plus++;
        else if(c == '-')   minus++;
        else            v.push_back(c-'0');
    }

    sort(v.begin(), v.end());

    ll mi = 0, ma = 0;
    
    // max
    int pos = 0;
    for(int i = 0; i < minus; i++)  ma -= v[pos], pos++;
    for(int i = 0; i < plus; i++)   ma += v[pos], pos++;
    ll largest = 0;
    for(int i = v.size()-1; i >= pos; i--) largest = 10*largest + v[i];
    ma += largest;

    // min
    if(minus == 0){
        reverse(v.begin(), v.end());
        int numofnum = plus + 1;
        for(int i = 0; i < v.size(); i++){
            ll times = 1;
            for(int j = 0; j < i/numofnum; j++) times *= 10;
            mi += times * v[i];
        }
    }else{
        mi = v[0];
        pos = 1;
        for(int i = 0; i < plus; i++)   mi += v[pos], pos++;
        for(int i = 1; i < minus; i++)  mi -= v[pos], pos++;
        mi -= largest;
    }

    cout << ma << " " << mi << endl;

    return 0;
}