#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    vector<string> T(n);
    for(int i = 0; i < n; i++) cin >> S[i];
    for(int i = 0; i < n; i++) cin >> T[i];
    for(int i = 0; i < n; i++){
        if(S[i] != T[i]){
            cout << (i+1) << endl;
            cout << S[i] << endl;
            cout << T[i] << endl;
            return 0;
        }
    } 
    return 0;
}