#include<iostream>
using namespace std;

typedef long long ll;

bool isLeap(ll y){
	return y%4 == 0 && (y%100 != 0 || y%400 == 0);
}

int main(){
	ll n;
	cin >> n;
	
	ll unit = 0, pass = 0;
	for(int i = 2015; i < 2415; i++){
		pass++;
		if(isLeap(i))	pass++;
		if(pass % 7 == 0)	unit++;
	}
	
	ll block = (n-2014) / 400;
	ll ans = unit * block;
	
	pass = (pass * block) % 7;
	for(ll i = 2015 + block * 400; i <= n; i++){
		pass++;
		if(isLeap(i))	pass++;
		if(pass % 7 == 0)	ans++;
	}
	
	cout << ans << endl;

	return 0;
}