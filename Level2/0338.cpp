#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int x = 0, y = 0;
    if(a > b) x++;
    else        y++;
    while(1){
        int f = round(100*(double)x/(x+y)) - a;
        int s = round(100*(double)y/(x+y)) - b;
        if(f == 0 && s == 0) break;
        
        if(f > s) y++;
        else       x++;
    }
    cout << (x+y) << endl; 
}