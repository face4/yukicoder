#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a;
    for(a = 1;;a++){
        int put = min(a, k)*a;
        if(put >= n)    break;
    }

    vector<vector<char>> ans(a, vector<char>(a, '.'));
    vector<int> col(a, 0);
    int pos = 0;
    for(int i = 0; i < a; i++){
        if(n == 0) break;
        int row = 0, lp = -1;
        for(int diff = 0; diff < a; diff++){
            int j = (pos+diff)%a;
            if(row == k)    break;
            if(col[j] == k) continue;
            lp = j;
            col[j]++, row++;
            ans[i][j] = '#';
            n--;
            if(n == 0)  break;
        }
        pos = (lp+1)%a;
    }
    cout << a << endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}