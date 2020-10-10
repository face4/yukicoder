#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    if(*min_element(v.begin(), v.end()) == 0){
        cout << -1 << endl;
    }else if(*max_element(v.begin(), v.end()) >= 4){
        // 4^4! > 1e9+7
        cout << mod << endl;
    }else{
        ll f = 1;
        int a[4] = {0, 1, 2, 6};
        for(int i = 0; i < n; i++){
            for(int j = 0; f <= mod && j < a[v[i]]; j++)   f *= v[i];
        }
        cout << (mod)%f << endl;
    }
    return 0;
}