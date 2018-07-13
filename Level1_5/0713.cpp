#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> prime;
    bool nonprime[1001] = {};
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i <= 1000; i++){
        if(!nonprime[i]){
            prime.push_back(i);
            for(int j = i+i; j <= 1000; j+=i)   nonprime[j] = true;
        }
    }

    int n;
    cin >> n;

    int ans = 0;
    for(int p : prime){
        if(p > n)   break;
        ans += p;
    }

    cout << ans << endl;
    
    return 0;
}