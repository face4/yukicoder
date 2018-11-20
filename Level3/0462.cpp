#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

int main(){
  int n, k;
  cin >> n >> k;

  ll ans = 1;
  
  if(k == 0){
	for(int i = 1; i <= n; i++) ans *= i, ans %= mod;
	cout << ans << endl;
	return 0;
  }

  vector<ll> v(k+2);
  for(int i = 0; i < k; i++) cin >> v[i];
  v[k] = (1ll<<n)-1;
  v[k+1] = 0;

  sort(v.begin(), v.end());

  for(int i = 0; i < k+1; i++){
	for(int j = i+1; j < k+1; j++){
	  if((v[i]&v[j]) != v[i]){
		cout << 0 << endl;
		return 0;
	  }
	}
  }

  for(int i = 0; i < k+1; i++){
	int tmp = bitset<64>(v[i+1]).count() - bitset<64>(v[i]).count();
	for(int j = 1; j <= tmp; j++) ans *= j, ans %= mod;
  }

  cout << ans << endl;
  
  return 0;
}
