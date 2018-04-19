#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if(abs(b) % abs(a) == 0){
        cout << (b/a);
    }else{
        cout << "NO";
    }
    cout << endl;
    return 0;
}