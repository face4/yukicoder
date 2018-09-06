#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];

    int ans = 10001;

    for(int i = 0; i < n; i++){
        priority_queue<pair<int,int>> pq;
        for(int j = 0; j < n; j++)  pq.push(make_pair(-a[j], 0));

        for(int j = 0; j < n; j++){
            int encount = b[(i+j)%n];
            pair<int,int> monster = pq.top(); pq.pop();
            monster.first -= encount/2;
            monster.second--;
            pq.push(monster);
        }

        int tmpmax = 0;
        while(!pq.empty()){
            pair<int,int> p = pq.top(); pq.pop();
            tmpmax = max(tmpmax, -p.second);
        }
        ans = min(ans, tmpmax);
    }

    cout << ans << endl;

    return 0;
}