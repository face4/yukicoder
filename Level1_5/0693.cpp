#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    vector<int> A;

    cin >> n;

    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end());

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += abs(i+1-A[i]);
    }

    cout << ans << endl;
    
    return 0;
}
