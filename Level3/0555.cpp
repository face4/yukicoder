// coding on smartphone
#include<iostream>
using namespace std;

const int INF = 1<<30;

int main(){
	int n, c, v;
	cin >> n >> c >> v;
	
	int dp[2*n];
	for(int i = 0; i < 2*n; i++)	dp[i] = INF;
	
	dp[1] = 0;
	for(int i = 1; i < 2*n; i++){
		for(int j = i+i; j < 2*n; j += i){
			dp[j] = min(dp[j], dp[i]+c+v*(j/i-1));
		}
	}
	
	int ans = dp[n];
	for(int i = n+1; i < 2*n; i++)	ans = min(ans, dp[i]);
	
	cout << ans << endl;
	
	return 0;
}