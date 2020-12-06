#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    map<int,int> m;
    do{
        int tmp = 0;
        for(int i = 0; i < n; i++)  tmp += max(0, a[v[i]]-b[i]);
        m[tmp]++;
    }while(next_permutation(v.begin(), v.end()));
    cout << m.rbegin()->second << endl;
    return 0;
}