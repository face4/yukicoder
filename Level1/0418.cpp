#include<iostream>
using namespace std;

int main(){
    char c;
    int sum = 0;
    for(; cin >> c;){
        if(c == 'n') sum++;
    }
    cout << sum << endl;
    return 0;
}