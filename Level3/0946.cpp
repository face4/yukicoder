// ?
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    int grundy[n+1];
    grundy[n] = 0;
    for(int i = n-1; i >= 0; i--){
        vector<int> v;
        int tmp = 0;
        for(int j = i+1; j <= n; j++)   tmp^=a[j-1], v.push_back(tmp^grundy[j]);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int j = 0;;j++){
            if(j >= v.size() || v[j] != j){
                grundy[i] = j;
                break;
            }
        }
    }
    cout << (grundy[0] ? "Takahashi" : "Takanashi") << endl;
    return 0;
}