#include<iostream>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int q, k;
    scanf("%d %d", &q, &k);

    multiset<ll> s;
    multiset<ll>::iterator it = s.begin();

    int op;
    ll val;
    int siz = 0;

    for(int i = 0; i < q; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%lld", &val);
            s.insert(val);
            siz++;
            if(siz == k){
                it = s.end();
                it--;
            }else if((*it) > val){
                it--;
            }
        }else if(op == 2){
            if(siz >= k){
                printf("%lld\n", *it);
                it = s.erase(it);
                siz--;
            }else{
                printf("-1\n");
            }
        }
    }

    return 0;
}