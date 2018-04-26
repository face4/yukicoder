#include<iostream>
using namespace std;

int one, five;

bool make(int val){
    return one >= val - val/5*5;
}

int main(){
    cin >> one >> five;
    for(int i = 1; i <= one+5*five; i++){
        if(make(i)) cout << i << endl;
    }
    return 0;
}