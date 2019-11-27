#include<iostream>
#include<vector>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int> v[32];
    int cnt = 0;
    for(int i = 0; i < 31; i++){
        for(int j = i+1; j < 31; j++){
            v[i].push_back(j);
            cnt++;
        }
    }
    for(int x = 1; x <= 31; x++){
        if((k>>(x-1))&1)    v[x].push_back(31), cnt++;
    }
    cout << 32 << " " << cnt << endl;
    for(int i = 0; i < 32; i++){
        for(int j : v[i]){
            cout << i+1 << " " << j+1 << endl;
        }
    }
    return 0;
}