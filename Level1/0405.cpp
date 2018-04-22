#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<string> x = {"I", "II", "III", "IIII", "V", "VI",
                        "VII", "VIII", "IX", "X", "XI" , "XII"};
    string s;
    int now, elapse;
    cin >> s >> elapse;
    for(int i = 0; i < 12; i++){
        if(s == x[i]){
            now = i;
            break;
        }
    }
    while(now + elapse < 0){
        now += 12;
    }
    cout << x[(now+elapse)%12] << endl;
    return 0;
}