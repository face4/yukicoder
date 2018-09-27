#include<iostream>
#include<set>
using namespace std;

typedef long long ll;
const ll INF = 1ll<<60;

int main(){
    set<pair<ll,ll>> job;
    // sentinel
    job.emplace(-2,-2);
    job.emplace(INF,INF);

    ll d, a, b, ans = 0;
    int q;

    cin >> d >> q;

    for(int i = 0; i < q; i++){
        cin >> a >> b;
        job.emplace(a,b);
        auto it = job.lower_bound({a,-1});
        it--;
        if(it->second + 1 >= a) a = it->first;
        else                    it++;
        while(b+1 >= it->first){
            b = max(b, it->second);
            it = job.erase(it);
        }
        job.emplace(a,b);

        ans = max(ans, b-a+1);
        cout << ans << endl;
    }

    return 0;
}