#include<iostream>
#include<numeric>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n], b[n];
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

  int dp[100001] = {};

  for(int i = 0; i < n; i++){
	for(int j = 100001; j >= a[i]; j--){
	  dp[j] = max(dp[j], dp[j-a[i]] + b[i]);
	}
  }

  int ans = 100001;
  int bsum = accumulate(b, b+n, 0);
  
  for(int i = 0; i < 100001; i++){
	ans = min(ans, max(i, bsum-dp[i]));
  }

  cout << ans << endl;
  
  return 0;
}
