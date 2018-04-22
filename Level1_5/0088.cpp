#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n = 0;
    char name[10];
    cin >> name;
    if(strcmp(name, "yukiko") == 0){
        n++;
    }
    char c;
    for(int i = 0; i < 64; i++){
        cin >> c;
        if(c != '.')    n++;
    }

    if(n%2 == 0)    cout << "oda";
    else            cout << "yukiko";
    
    cout << endl;
    return 0;
}