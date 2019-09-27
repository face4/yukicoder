#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;

// なるべく無駄を排したつもり
// 計算量解析が出来ないのでわからない

int main(){
    int n;
    cin >> n;
    multiset<int> m;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        m.insert(x);
        sum += x;
    }

    int q;
    cin >> q;
    vector<int> x(q);
    multiset<int> que;
    for(int i = 0; i < q; i++){
        cin >> x[i];
        que.insert(x[i]);
    }

    for(int i = 0; i < q; i++){
        que.erase(que.find(x[i]));
        int mindiv = que.empty() ? 1<<30 : *que.begin();
        auto it = m.lower_bound(x[i]);
        vector<int> pool;
        while(it != m.end()){
            int val = *it;
            sum -= val;
            val %= x[i];
            sum += val;
            if(val >= mindiv){
                pool.push_back(val);
            }
            it = m.erase(it);
        }
        for(int x : pool)   m.insert(x);
        cout << sum << endl;
    }

    return 0;
}