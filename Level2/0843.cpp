#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    vector<int> p;
    bool nonp[500001] = {};
    nonp[0] = nonp[1] = true;
    for(int i = 2; i < 500001; i++){
        if(nonp[i]) continue;
        p.push_back(i);
        for(int j = i+i; j < 500001; j += i)  nonp[j] = true;
    }

    int n;
    cin >> n;

    // 2.5e8 ??
    int ans = 0;
    for(int i = 0; i < p.size() && p[i] <= 1000; i++){
        int x = p[i]*p[i];
        for(int j = 2; j <= n && x-j >= j; j++)   if(x-j <= n && !nonp[j]&&!nonp[x-j])   ans+=(j==x-j ? 1 : 2);
    }

    cout << ans << endl;

    return 0;
}