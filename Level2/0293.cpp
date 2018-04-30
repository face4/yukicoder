#include<iostream>
using namespace std;

bool comp(int a, int b){
    if(a == 4 && b == 7)        return true;
    else if(a == 7 && b == 4)   return false;
    else    return a > b;
}

int main(){
    string a, b;
    cin >> a >> b;
    if(a.length() != b.length()){
        cout << (a.length() > b.length() ? a : b) << endl;
    }else{
        for(int i = 0; i < a.length(); i++){
            int xa = (int)(a[i]-'0');
            int xb = (int)(b[i]-'0');
            if(xa != xb){
                if(comp(xa, xb))    cout << a << endl;
                else                cout << b << endl;
                break;
            }
        }
    }

    return 0;
}