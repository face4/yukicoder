#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    string t = "";
    for(int i = 0; i < n; i++){
        t += s.substr(n-1-i, 1);
        if(i%3 == 2 && i != n-1)    t += ",";
    }

    reverse(t.begin(), t.end());

    cout << t << endl;

    return 0;
}