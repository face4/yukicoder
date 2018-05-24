// coding on smartphone
#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> hole;
int w, h;
char mat[20][20];

void bfs(int i, int j){
	if(i < 0 || i > h || j < 0 || j > w)	return;
	
	if(mat[i][j] == '.'){
		hole.push_back({i, j});
		mat[i][j] = '#';
		bfs(i-1, j);
		bfs(i+1, j);
		bfs(i, j+1);
		bfs(i, j-1);
	}
}

int main(){
	cin >> w >> h;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> mat[i][j];
		}
	}
	
	bool found = false;
	int ans = 50;
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(mat[i][j] == '.'){
				if(!found){
					 bfs(i, j);
					 found = true;
				}else{
					for(int k = 0; k < hole.size(); k++){	
						int tmp = abs(i-hole[k].first) + abs(j-hole[k].second);
						ans = min(tmp, ans);
					}
				}
			}
		}
	}
	
	ans--;
	cout << ans << endl;
	return 0;
}
