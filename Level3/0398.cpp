#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int fact[7];
    fact[0] = 1;
    for(int i = 1; i <= 6; i++) fact[i] = i*fact[i-1];
    double x;
    cin >> x;
    int n = (int)(x*4);
    ll ans = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = i; j <= 100; j++){
            if(i+j > n) break;
            for(int k = j; k <= 100; k++){
                if(n-i-j-k < k) break;
                int l = n-i-j-k;
                if(l > 100) continue;
                int a = i, b = l;
                map<int,int> tmp;
                tmp[a]++;   tmp[i]++;
                tmp[j]++;   tmp[k]++;
                tmp[l]++;   tmp[b]++;
                ll add = fact[6];
                for(auto p : tmp)   add /= fact[p.second];
                ans += add;

                if(l != 100){
                    tmp[b]--;
                    add = fact[6];
                    for(auto p : tmp)   add /= fact[p.second];
                    ans += add*(100-l);
                    tmp[b]++;
                }
                if(i != 0){
                    tmp[a]--;
                    add = fact[6];
                    for(auto p : tmp)   add /= fact[p.second];
                    ans += add*i;
                    tmp[a]++;
                }

                if(i != 0 && l != 100){
                    tmp[i]--;
                    tmp[l]--;
                    add = fact[6];
                    for(auto p : tmp)   add /= fact[p.second];
                    ans += add*i*(100-l);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}