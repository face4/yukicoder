#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q[n];
    for(int i = 0; i < n; i++){
        int p;  cin >> p;
        while(p-- > 0){
            int x;  cin >> x;
            q[i].push(x);
        }
    }
    queue<int> j;
    for(int i = 0; i < n; i++)  if(!q[i].empty())   j.push(i);
    vector<int> v;
    while(!j.empty()){
        int x = j.front();  j.pop();
        v.push_back(q[x].front());  q[x].pop();
        if(!q[x].empty())   j.push(x);
    }
    for(int i = 0; i < v.size(); i++)   cout << v[i] << " \n"[i+1==v.size()];
    return 0;
}