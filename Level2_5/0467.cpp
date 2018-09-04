#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> d(n);
    for(int i = 0; i < n; i++)  cin >> d[i];
    sort(d.begin(), d.end());

    int x, y;
    cin >> x >> y;

    int m = max(abs(x), abs(y));
    if(m == 0){
        cout << 0 << endl;
    }else if(*lower_bound(d.begin(), d.end(), m) == m){
        cout << 1 << endl;
    }else{
        cout << max(2, (m+d[n-1]-1)/d[n-1]) << endl;
    }

    return 0;
}