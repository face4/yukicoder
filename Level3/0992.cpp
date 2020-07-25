#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int mod = 1000000007;

template<typename T, typename F>
struct Seg{
private:
    vector<T> node;
    int n;
    F f;
    T def;

public:
    Seg(int siz, T d, F f) : def(d), f(f) {
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, def);
    }
    Seg(vector<T> v, T d, F f) : def(d), f(f){
        n = 1;
        while(n < v.size())  n *= 2;
        node.resize(2*n-1);
        for(int i = 0; i < v.size(); i++)   node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = f(node[2*i+1], node[2*i+2]);
    }

    void update(int x, T val){
        x += n-1;
        node[x] = val; /* ! */
        while(x){
            x = (x-1)/2;
            node[x] = f(node[2*x+1], node[2*x+2]);
        }
    }

    T query(int a, int b){
        int L = a+n-1, R = b+n-1;
        T ret = def;
        while(L < R){
            if((R&1) == 0)  ret = f(ret, node[--R]);
            if((L&1) == 0)  ret = f(ret, node[L++]);
            L >>= 1, R >>= 1;
        }
        return ret;
    }
};

struct Box{
    int length, count;
};

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        vp.push_back({x, -i});
    }
    sort(vp.begin(), vp.end());
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[-vp[i].second] = i;
    }
    auto f = [](Box a, Box b){
        if(a.length < b.length){
            return b;
        }else if(a.length > b.length){
            return a;
        }else if(a.length == b.length){
            (a.count += b.count) %= mod;
            return a;
        }
        return a;
    };
    Seg<Box, decltype(f)> argmax(n+1, {0,0}, f);
    argmax.update(0, {0,1});
    for(int i = 0; i < n; i++){
        int pos = -vp[i].second+1;
        Box now = argmax.query(0, pos);
        now.length++;
        argmax.update(pos, now);
    }
    cout << argmax.query(1, n+1).count << endl;
    return 0;
}

