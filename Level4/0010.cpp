// coding on smartphone
#include<iostream>
using namespace std;

int main(){
	int n, tot, a[51];
	bool dp[51][100001] = {};
	
	cin >> n >> tot;
	for(int i = n-1; i >= 0; i--)	cin >> a[i];
	
	dp[0][tot] = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 100001; j++){
			if(!dp[i][j])	continue;
			if(j-a[i] >= 0)	dp[i+1][j-a[i]] = true;
			if(j%a[i] == 0)	dp[i+1][j/a[i]] = true;
		}
	}
	
	int val = a[n-1], pos = n-2;
	while(pos >= 0){
		if(dp[pos][val + a[pos]]){
			val += a[pos];
			cout << "+";
		}else{
			val *= a[pos];
			cout << "*";
		}
		pos--;
	}
	cout << endl;
	
	return 0;
}