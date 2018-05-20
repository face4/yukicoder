#include<iostream>
using namespace std;

const int N = (1<<15);
bool dp[N];

int main(){
    for(int i = 0; i < N; i++)  dp[i] = false;
    dp[0] = true;
    int n;
    cin >> n;
    
    int x;
    for(int j = 1; j <= n; j++){
        cin >> x;
        for(int i = 0; i < N; i++){
            if(dp[i])   dp[i^x] = true;
        }
    }

    int count = 0;
    for(int i = 0; i < N; i++){
        if(dp[i])    count++;
    }

    cout << count << endl;
    return 0;
}