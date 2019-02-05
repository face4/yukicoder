#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

struct SegmentTree{
    vector<int> node, pos;
    int n;
    
    SegmentTree(vector<int> v){
        int s = v.size();
        n = 1;
        while(n < s) n *= 2;
        node.resize(2*n-1, 0);
        pos.resize(2*n-1, 0);
        for(int i = 0; i < s; i++)      node[i+n-1] = v[i], pos[i+n-1] = i;
        for(int i = n-2; i >= 0; i--){
            node[i] = max(node[2*i+1], node[2*i+2]);
            if(node[2*i+1] >= node[2*i+2])  pos[i] = pos[2*i+1];
            else                            pos[i] = pos[2*i+2];
        }
    }

    // [a, b)の最大値 kは現在地,[l, r)をカバー
    int getmax(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        
        if(a >= r || b <= l)    return -1;

        if(a <= l && r <= b)    return pos[k];

        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);

        if(vl == -1)    return vr;
        if(vr == -1)    return vl;
        if(node[n-1+vl] >= node[n-1+vr])  return vl;
        else                return vr;
    }
};

int main(){
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    SegmentTree seg(v);

    ll ans = 0;
    int posi, posj;
    for(int i = 0; i < n-1; i++){
        int pos = seg.getmax(i+1, min(n, i+d+1));
        ll tmp = (ll)k * (v[pos]-v[i]);
        if(tmp > ans){
            ans = tmp;
            posi = i, posj = pos;
        }
    }

    cout << ans << endl;
    if(ans) cout << posi << " " << posj << endl;

    return 0;
}