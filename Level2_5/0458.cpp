#include<iostream>
#include<vector>
using namespace std;

int main(){
    bool np[20001] = {};
    vector<int> prime;
    np[0] = np[1] = true;
    for(int i = 2; i < 20001; i++){
        if(!np[i]){
            prime.push_back(i);
            for(int j = i+i; j < 20001; j+=i)   np[j] = true;
        }
    }

    int dp[20001] = {};
    for(int i = 1; i < 20001; i++)  dp[i] = -1;

    for(int p : prime){
        for(int i = 20000-p; i >= 0; i--){
            if(dp[i] != -1) dp[i+p] = max(dp[i+p], dp[i]+1);
        }
    }

    int n;
    cin >> n;

    cout << dp[n] << endl;
    
    return 0;
}