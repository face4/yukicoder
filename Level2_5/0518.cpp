#include<iostream>
#include<map>
using namespace std;

int main(){
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    map<string, int> o;
    o["IV"] = 4;
    o["IX"] = 9;
    o["XL"] = 40;
    o["XC"] = 40;
    o["CD"] = 400;
    o["CM"] = 900;

    int n;
    cin >> n;

    string r;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> r;
        for(int j = 0; j < r.length(); j++){
            if(j < r.length()-1){
                string tmp = r.substr(j, 2);
                if(o.count(tmp)){
                    sum += o[tmp];
                    j++;
                }else{
                    sum += m[r[j]];
                }
            }else{
                sum += m[r[j]];
            }
        }
    }

    if(sum > 3999){
        cout << "ERROR" << endl;
        return 0;
    }

    // ここを頑張って
    cout << endl;

    return 0;
}