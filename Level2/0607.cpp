#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int sum[n] = {};

    int x;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> x;
            sum[j] += x;
        }

        int left = -1, right = 0, ans = 0;
        for(right = 0; right < n; right++){
            ans += sum[right];
            while(ans>777 && left < right){
                left++;
                ans -= sum[left];
            }

            if(ans==777){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}