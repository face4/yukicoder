#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<string> used;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        used.insert(s);
    }
    string vowel = "aaeiuu", conso = "bgmnr";
    do{
        do{
            for(int i = 0; i < 6; i++){
                string t = "";
                int vpos = 0, cpos = 0;
                for(int j = 0; j < 5; j++){
                    if(i == j)  t += vowel.substr(vpos++, 1);
                    t += conso.substr(cpos++, 1);
                    t += vowel.substr(vpos++, 1);
                }
                if(i == 5)  t += vowel.substr(vpos++, 1);
                if(used.count(t) == 0){
                    cout << t << endl;
                    return 0;
                }
            }
        }while(next_permutation(conso.begin(), conso.end()));
    }while(next_permutation(vowel.begin(), vowel.end()));
    cout << "NO" << endl;
    return 0;
}