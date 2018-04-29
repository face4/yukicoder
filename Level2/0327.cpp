#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    n++;
    string s = "";
    while(n > 0){
        n--;
        string append = {(char)('A' + n%26)};
        s = append + s;
        n /= 26;
    }

    cout << s << endl;
    return 0;
}