// 解説を見た
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    // int n;
    // cin >> n;
    // vector<vector<bool>> bit(n, vector<bool>(61, 0));
    // for(int i = 0; i < n; i++){
    //     ll x;   cin >> x;
    //     for(int j = 0; j < 61; j++){
    //         bit[i][60-j] = x%2==1;
    //         x >>= 1;
    //     }
    // }
    // int rank = 0;
    // for(int i = 0; i <= 60; i++){
    //     int j;
    //     for(j = rank; j < n; j++){
    //         if(bit[j][i])   break;
    //     }
    //     if(j == n)  continue;
    //     swap(bit[rank], bit[j]);
    //     for(j = 0; j < n; j++){
    //         if(j == rank)   continue;
    //         if(bit[j][i]){
    //             for(int k = 0; k <= 60; k++){
    //                 bit[j][k] = bit[j][k] ^ bit[rank][k];
    //             }
    //         }
    //     }
    //     rank++;
    // }
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    int rank = 0;
    for(int i = 60; i >= 0; i--){
        int j;
        for(j = rank; j < n; j++){
            if((v[j]>>i)&1) break;
        }
        if(j == n)  continue;
        swap(v[rank], v[j]);
        for(j = 0; j < n; j++){
            if(j == rank)   continue;
            if((v[j]>>i)&1) v[j] ^= v[rank];
        }
        rank++;
    }
    cout << (1ll<<rank) << endl;
    return 0;
}