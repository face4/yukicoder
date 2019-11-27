#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    if(a[0] > a[n-1]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<int> res;
    vector<bool> used(n, 0);
    for(int i = 1; i < n-1; i++){
        if(a[i] > a[0]) used[i] = true, res.push_back(a[i]);
    }
    for(int i = n-2; i >= 1; i--){
        if(!used[i] && a[i] < a[n-1]) res.push_back(a[i]);
    }
    res.push_back(a[0]);
    for(int i = 0; i < n-1; i++)    cout << res[i] << " \n"[i+1==n-1];
    return 0;
}