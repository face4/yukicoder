#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length();
    int m = stoi(s);

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(i == j) continue;
            string t = s;
            swap(t[i], t[j]);
            m = max(stoi(t), m);
        }
    }

    cout << m << endl;
    return 0;
}