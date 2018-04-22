#include<iostream>
using namespace std;

int main(){
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    mm += 5;
    if(mm >= 60){
        hh = (hh + 1) % 24;
        mm -= 60;
    }
    if(hh < 10)  cout << "0";
    cout << hh << ":";
    if(mm < 10)  cout << "0";
    cout << mm << endl;
    
    return 0;
}