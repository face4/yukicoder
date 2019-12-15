#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<int> a(h), b(w);
    for(int i = 0; i < h; i++)  cin >> a[i];
    for(int i = 0; i < w; i++)  cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> v[h*w], indeg(h*w, 0);
    for(int i = 0; i < h; i++){
        for(int j = 0; j+1 < w; j++){
            int x = i*w+j, y = i*w+j+1;
            if(j+1 < a[i])  v[y].push_back(x), indeg[x]++;
            else            v[x].push_back(y), indeg[y]++;
        }
    }
    for(int j = 0; j < w; j++){
        for(int i = 0; i+1 < h; i++){
            int x = i*w+j, y = (i+1)*w+j;
            if(i+1 < b[j])  v[y].push_back(x), indeg[x]++;
            else            v[x].push_back(y), indeg[y]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < h*w; i++)    if(indeg[i]==0) q.push(i);
    int ans[h][w], val = h*w;
    while(!q.empty()){
        int x = q.front();  q.pop();
        ans[x/w][x%w] = val--;
        for(int next : v[x]){
            indeg[next]--;
            if(indeg[next] == 0)    q.push(next);
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << ans[i][j] << " \n"[j==w-1];
        }
    }
    return 0;
}