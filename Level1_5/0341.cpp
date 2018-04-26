#include<iostream>
using namespace std;

int main(){
    string s, t = "…";
    cin >> s;
    int ma = 0, count = 0;
    for(int i = 0; i <= s.size() - 3; i += 3){
        string n{s[i],s[i+1],s[i+2]};
        if(n == t)  count++;
        else        count = 0;
        ma = max(ma, count);
    }

    cout << ma << endl;
    return 0;
}