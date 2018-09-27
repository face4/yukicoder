#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

struct BIT{
    // 1-origin
    vector<int> v;
    int n;

    BIT(int _n):
        v(vector<int>(_n+1, 0)), n(_n) {}

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += v[i];
            i -= lsb(i);
        }
        return s;
    }
    
    // 閉区間[l, r]の和
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }

    void add(int i, int x){
        while(i <= n){
            v[i] += x;
            i += lsb(i);
        }
    }

private:
    // least significant bit
    int lsb(int i){
        return i & -i;
    }
};

#define MAX 1000000
int cnt[MAX] = {};

int main(){
    int n, k, w;
    cin >> n >> k;

    BIT bit(MAX);

    for(int i = 0; i < n; i++){
        cin >> w;
        if(w > 0){
            if(bit.sum(w, MAX) < k){
                bit.add(w, 1);
                cnt[w]++;
            }
        }else{
            if(cnt[-w]){
                cnt[-w]--;
                bit.add(-w, -1);
            }
        }
    }

    cout << bit.sum(1,MAX) << endl;
}

