#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    vector<int> factor(2e6+1, 0);
    vector<bool> nonprime(2e6+1, false); // 実はnonprimeではない(int j = i+iではなくiとしているため)
    for(int i = 2; i < 2e6+1; i++){
        if(!nonprime[i]){
            for(int j = i; j < 2e6+1; j+=i){
                nonprime[j] = true;
                factor[j]++;
            }
        }
    }

    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(factor[i] >= k)    cnt++;
    }

    cout << cnt << endl;
    return 0;
}

// 3560ms(!!)
// int count(int n){
//     int cnt = 0;
//     for(int i = 2; i <= sqrt(n); i++){
//         if(n%i == 0){
//             cnt+=1;
//             n/=i;
//             while(n%i == 0) n/=i;
//         }
//     }
//     if(n != 1)  cnt++;
//     return cnt;
// }

// int main(){
//     int n, k;
//     cin >> n >> k;
//     int ans = n-1;

//     for(int i = 2; i <= n; i++){
//         if(count(i) < k)    ans--;
//     }

//     cout << ans << endl;
//     return 0;
// }