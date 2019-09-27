#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int k;  cin >> k;
    vector<int> a(n-1);
    for(int i = 0; i < n-1; i++)  cin >> a[i];
    sort(a.begin(), a.end());
    auto f = [&](int pos)->bool{
        int score = a[pos] + k;
        int count = 0, l = 0, r = n-2;
        if(l == pos)    l++;
        if(r == pos)    r--;
        while(l < r){
            if(a[l]+a[r] > score){
                count++, l++, r--;
            }else{
                l++;
            }
            if(l == pos)    l++;
            if(r == pos)    r--;
        }
        return count >= m;
    };
    if(f(n-2)){
        cout << -1 << endl;
        return 0;
    }
    int l = -1, r = n-2;
    while(r-l > 1){
        int mid = (l+r)/2;
        if(f(mid))  l = mid;
        else        r = mid;
    }
    cout << a[r] << endl;
    return 0;
}
