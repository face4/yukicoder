#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

struct BIT{
    vector<int> node;
    int n;
    BIT(int siz){
        n = siz+1;
        node.resize(n, 0); 
    }

    void add(int i, int x){
        while(i < n){
            node[i] += x;
            i += i&-i;
        }
    }

    int sum(int i){
        int ret = 0;
        while(i > 0){
            ret += node[i];
            i -= i&-i;
        }
        return ret;
    }
};

BIT bit(200000);
vector<int> a[200000];
int n;
ll ans = 0;

void dfs(int cur){
    ans += bit.sum(cur+1);
    bit.add(cur+1, 1);
    for(int next : a[cur]){
        dfs(next);
    }
    bit.add(cur+1, -1);
}

int main(){
    cin >> n;
    int x;
    for(int i = 1; i <= n-1; i++){
        cin >> x;
        a[x].push_back(i);
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}