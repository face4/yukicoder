#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int pos = 0, count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'A'){
            count += (i - pos);
            pos++;
        }
    }
    cout << count << endl;
    return 0;
}