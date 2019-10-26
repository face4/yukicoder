#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d\n", &n, &m);
    vector<int> v[7*24*60];   
    auto f = [](int d, int h, int m)->int{
        return (d-2)*24*60+h*60+m;
    };
    while(m-- > 0){
        int d1, h1, m1, d2, h2, m2;
        scanf("%d %d:%d %d %d:%d\n", &d1, &h1, &m1, &d2, &h2, &m2);
        int from = f(d1, h1, m1), to = f(d2, h2, m2);
        v[from].push_back(to);
    }
    int ans = 0;
    multiset<int> stay;
    for(int i = 0; i < 7*24*60; i++){
        for(int j : v[i])   stay.insert(j);
        while(stay.size() > n)  stay.erase(--stay.end());
        while(!stay.empty() && *stay.begin() == i){
            stay.erase(stay.begin());
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}