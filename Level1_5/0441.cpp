#include<iostream>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    if(s == t && (s=="2" || s=="0")){
        cout << "E" << endl;
    }else if(s <= "1" || t <= "1"){
        cout << "S" << endl;
    }else{
        cout << "P" << endl;
    }
    return 0;
}