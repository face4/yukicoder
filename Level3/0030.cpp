// coding on smartphone
#include<iostream>
using namespace std;
typedef long long ll;

int mat[101][101];
ll dp[101][101] = {};
bool med[101] = {};
int n;

ll dfs(int i, int j){
	if(dp[i][j] >= 0)	return dp[i][j];
	ll ret = 0;
	if(i == j)	return 1 - med[j];
	for(int k = 1; k < n; k++){
		if(mat[i][k])	ret += dfs(k, j) * mat[i][k];
	}
	return dp[i][j] = ret;
}

int main(){
	int m, p, q, r;
	cin >> n >> m;
	
	for(int i = 1; i < 101; i++){
		for(int j = 1; j < 101; j++){
			dp[i][j] = -1;
		}
	}
	
	for(int i = 0; i < m; i++){
		cin >> p >> q >> r;
		med[r] = true;
		mat[r][p] = q;
	}
	
	for(int i = 1; i < n; i++){
		cout << dfs(n, i) << endl;
	}
	
	return 0;
}