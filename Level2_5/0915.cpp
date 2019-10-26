// ?
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int q;
    cin >> q;
    while(q-- > 0){
        ll a, b, c;
        cin >> a >> b >> c;
        if(c == 1){
            cout << -1 << endl;
            continue;
        }
        vector<int> v;
        while(a){
            v.push_back(a%c);
            a /= c;
        }
        int n = v.size();
        int op = n;
        if(n > 1){
            int from = n-2;
            if(v[n-1] == 1 && v[n-2] < c-1){
                from = n-3;
            }
            while(from >= 0)  op += v[from--]>0;
        }
        cout << op*b << endl;
    }
    return 0;
}