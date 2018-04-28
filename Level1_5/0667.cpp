#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int o = 0, x = 0;
    vector<double> result;
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 1; i <= len; i++){
        if(s[len-i] == 'o')     o++;
        else if(s[len-i] = 'x') x++;

        result.push_back(100.0*o / (o+x));
    }

    for(int i = len-1; i >= 0; i--){
        cout << fixed << setprecision(6) << result[i] << endl;
    }

    return 0;
}