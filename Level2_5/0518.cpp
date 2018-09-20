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
    o["XC"] = 90;
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

    string res = "";
    while(sum >= 1000)  res += "M", sum -= 1000;
    if(sum >= 900)      res += "CM", sum -= 900;
    if(sum >= 500)      res += "D", sum -= 500;
    if(sum >= 400)      res += "CD", sum -= 400;
    while(sum >= 100)   res += "C", sum -= 100;
    if(sum >= 90)       res += "XC", sum -= 90;
    if(sum >= 50)       res += "L", sum -= 50;
    if(sum >= 40)       res += "XL", sum -= 40;
    while(sum >= 10)    res += "X", sum -= 10;
    if(sum >= 9)        res += "IX", sum -= 9;
    if(sum >= 5)        res += "V", sum -= 5;
    if(sum >= 4)        res += "IV", sum -= 4;
    while(sum >= 1)     res += "I", sum -= 1;

    cout << res << endl;

    return 0;
}