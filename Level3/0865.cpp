#include<iostream>
#include<vector>
using namespace std;
const int INF = 1<<30;

struct STsum{
private:
    int n;
    vector<int> dat;
public:
    STsum(vector<int> ini){
        int siz = ini.size();
        n = 1;
        while(n < siz)   n *= 2;
        dat.resize(2*n-1, -INF);
        for(int i = 0; i < siz; i++)    dat[n - 1 + i] = ini[i];
        for(int i = n-2; i >= 0; i--)   dat[i] = dat[2*i+1]+dat[2*i+2];
    }

    void update(int x, int val){
        x += (n-1);
        dat[x] += val;
        while(x > 0){
            x = (x-1)/2;
            dat[x] = dat[2*x+1]+dat[2*x+2];
        }
    }
    
    // focus on k-th node, who controls [l, r)
    int query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return dat[k];

        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    STsum seg(a);
    int ans = 0;
    for(int i = 0; i <= n-24; i++)   ans = max(ans, seg.query(i, i+24));
    int q;
    cin >> q;
    while(q-- > 0){
        int t, v;
        cin >> t >> v;
        t--;
        seg.update(t, v-a[t]);
        a[t] = v;
        for(int i = max(0, t-23); i <= min(n-24, t); i++)   ans = max(ans, seg.query(i, i+24));
        cout << ans << endl;
    }
    return 0;
}