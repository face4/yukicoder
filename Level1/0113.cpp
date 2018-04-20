#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int x = 0, y = 0;
    char c;
    for(; cin >> c;){
        switch(c){
            case 'N': y++; break;
            case 'E': x++; break;
            case 'W': x--; break;
            case 'S': y--; break;
        }
    }

    cout << sqrt(x*x + y*y) << endl;
    return 0;
}