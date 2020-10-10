#include<iostream>
using namespace std;

typedef long long ll;
bool nonp[5000001] = {};

int main(){
    nonp[1] = true;
    for(int i = 2; i < 5000001; i++){
        if(nonp[i]) continue;
        for(int j = i+i; j < 5000001; j += i){
            nonp[j] = true;
        }
    }
    int t;
    scanf("%d", &t);
    ll a;
    int p;
    while(t-- > 0){
        scanf("%lld %d", &a, &p);
        printf("%d\n", nonp[p] ? -1 : a%p==0 ? 0 : 1);
    }
    return 0;
}

