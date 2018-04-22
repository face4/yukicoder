#include<iostream>
using namespace std;

int main(){
    char c;
    int score = 0;
    for(; cin >> c;){
        if(c == '0'){
            score += 10;
        }else{
            score += (int)(c-'0');
        }
    }
    cout << score << endl;
    return 0;
}