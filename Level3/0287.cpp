// coding on smartphone
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	
	ll dp[8][601] = {};
	for(int i = 0; i <= n; i++) dp[0][i] = 1;
	
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 601; j++){
			if(dp[i][j] == 0) continue;
			for(int k = 0; k <= n; k++){
				if(j+k > 600) break;
				dp[i+1][j+k] += dp[i][j];
			}
		}
	}
	
	cout << dp[7][6*n] << endl;
	
	return 0;
}