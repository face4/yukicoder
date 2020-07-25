#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    vector<int> s = v;
    sort(s.begin(), s.end());
    for(int i = 0; i < n; i++){
        cout << upper_bound(s.begin(),s.end(),v[i]-d)-s.begin() << endl;
    }
    return 0;
}