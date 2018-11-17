// coding on smartphone
#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> i2g, ans;
vector<vector<int>> g2i;
int one, turn = -2;

void init(int n){
	i2g.resize(n);
	g2i.resize(n);
	ans.resize(n, 0);
	one = 1;
	for(int i = 0; i < n; i++){
		i2g[i] = i;
		g2i[i].assign(1, i);
	}
}

void unite(int a, int b){
	int ga = i2g[a], gb = i2g[b];
	if(ga == gb)	return;
	
	if(g2i[ga].size() < g2i[gb].size())	swap(ga, gb);
	
	if(ga == one){
		for(int x : g2i[gb])	if(ans[x] == 0) ans[x] = turn+1;
	}
	if(gb == one){
		for(int x : g2i[ga])	if(ans[x] == 0) ans[x] = turn+1;
	}
	
	for(int x : g2i[gb])	i2g[x] = ga;
	g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());
	g2i[gb].clear();
	
	if(gb == one)	one = ga;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	
	set<pair<int,int>> s;
	int a[m], b[m], c[q], d[q];
	
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		s.insert({a[i], b[i]});
	}
	for(int i = 0; i < q; i++){
		cin >> c[i] >> d[i];
		s.erase({c[i], d[i]});
	}
	
	init(n+1);
	
	for(pair<int,int> p : s){
		unite(p.first, p.second);
	}
	
	for(turn = q-1; turn >= 0; turn--){
		unite(c[turn], d[turn]);
	}
	
	for(int i = 2; i <= n; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}