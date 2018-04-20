#include<iostream>
using namespace std;

int main(){
    int score = 0;
    char c;
    for(; abs(score) != 3 && cin >> c;){
        if(c == 'O'){
            if(score > 0)  score++;
            else           score = 1;
        }else if(c == 'X'){
            if(score < 0)  score--;
            else           score = -1;
        }
    }

    if(abs(score) == 3){
        if(score == 3)  cout << "East";
        else            cout << "West";
    }else{
        cout << "NA";
    }

    cout << endl; 
    return 0;
}