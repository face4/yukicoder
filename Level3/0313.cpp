#include<iostream>
using namespace std;

int main(){
    int a[10] = {20104, 20063, 19892, 20011, 19874, 20199, 19898, 20163, 19956, 19841};
    int b[10] = {};
    string s;
    cin >> s;

    s.erase(1,1);
    for(int i = 0; i < s.length(); i++) b[s[i]-'0']++;

    int less, more;
    for(int i = 0; i < 10; i++){
        if(a[i] < b[i]) more = i;
        if(a[i] > b[i]) less = i;
    }

    cout << more << " " << less << endl;
    return 0;
}