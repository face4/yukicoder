#include<iostream>
using namespace std;

int main(){
    string n, k;
    cin >> n >> k;

    int ni = 0, nk = 0;
    for(int i = 0; i < n.length(); i++){
        ni *= 10;
        ni += n[i]-'0';
        ni %= 6;
    }

    for(int i = 0; i < k.length(); i++){
        nk *= 10;
        nk += k[i]-'0';
        nk %= 6;
    }
    if(nk == 0) nk = 6;

    int tmp = 1;
    for(int i = 0; i < nk; i++){
        tmp *= ni;
        tmp %= 6;
    }
    
    cout << "285714"[(tmp+5)%6] << endl;

    return 0;
}