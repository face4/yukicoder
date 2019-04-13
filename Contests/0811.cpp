#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    bool nonp[100001] = {};
    vector<int> p;
    for(int i = 2; i < 100001; i++){
        if(nonp[i]) continue;
        p.push_back(i);
        for(int j = i+i; j < 100001; j += i)    nonp[j] = true;
    }

    int N, k;
    cin >> N >> k;
    int n = N;
    map<int, int> fact;
    for(int prime : p){
        while(n%prime == 0){
            n /= prime;
            fact[prime]++;
        }
    }
    if(n != 1)  fact[n]++;

    n = N;
    int ans = -1;
    ll score = 0;
    for(int i = 1; i < n; i++){
        map<int,int> use;
        int cp = i;
        for(int j = 2; j*j <= cp; j++){
            while(cp%j == 0)    cp /= j, use[j]++;
        }
        if(cp != 1) use[cp]++;
        int tmp = 0;
        ll tmps = 1;
        for(auto x : use){
            int add = min(x.second, fact[x.first]);
            tmp += add;
            tmps *= x.second+1;
        }
        if(tmp >= k && tmps > score)    ans = i, score = tmps;
    }
    cout << ans << endl;
    return 0;
}