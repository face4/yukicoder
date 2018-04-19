#include<iostream>
using namespace std;

int main(){
    int n, s, a, b;
    cin >> n >> a >> b;
    if((b-a) < 1){
        cout << "-1" << endl;
        return 0;
    }else{
        s = b-a;
    }

    n--;
    while(n-- > 0){
        cin >> a >> b;
        if(b-a != s){
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << s << endl;
    return 0;
}