#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m;
    vector<int> v(m+1, 0);
    while(n--)  cin >> x, v[(x<=m)*x]++;
    for(int i = 1; i <= m; i++) cout << i << " " << v[i] << endl;
    return 0;
}