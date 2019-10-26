#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int q;
    cin >> q;
    while(q-- > 0){
        ll n, k;
        cin >> n >> k;
        if(k == 1){
            cout << n-1 << endl;
            continue;
        }
        ll depth = 0, sum = 1, bef = 1;
        while(sum < n){
            depth++;
            sum += bef*k;
            bef *= k;
        }
        cout << depth << endl;
    }
    return 0;
}