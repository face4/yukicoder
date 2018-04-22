#include<iostream>
#include<string>
using namespace std;

int main(){
    int res = 0, x;
    for(int i = 0; i < 5; i++){
        cin >> x;
        if(x % 15 == 0){
            res += 8;
        }else if(x % 3 == 0 || x % 5 == 0){
            res += 4;
        }else{
            res += to_string(x).length();
        }
    }
    cout << res << endl;
    return 0;
}