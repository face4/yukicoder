#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[n];

    for(int i = 0; i < n; i++)  cin >> s[i], s[i] += '{';

    string ret = "";

    while(1){
        sort(s, s+n);
        if(s[0][0] == '{')  break;
        ret += s[0][0];
        s[0] = s[0].substr(1);
    }

    cout << ret << endl;

    return 0;
}