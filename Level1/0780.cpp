#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    if(a+1 <= b){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    int happy = min(a+1, b);
    cout << a+b+1-happy*2 << endl;
    
    return 0;
}