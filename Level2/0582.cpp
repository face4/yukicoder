#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int c[n];
    for(int i = 0; i < n; i++)  cin >> c[i];

    int two = 0, one = 0;
    bool judge = true;

    for(int i = 0; i < n; i++){
        if(c[i] > 2)    judge = false;
        else if(c[i] == 1)  one++;
        else if(c[i] == 2)  two++;
    }

    if(judge && one%2 == 1 && (two == 0 || two == 1)){
        cout << "A" << endl;
    }else{
        cout << "B" << endl;
    }

    return 0;
}