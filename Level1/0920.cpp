#include<iostream>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    for(int i = 1;; i++){
        if(max(0,(i-x))+max(0,(i-y)) > z){
            cout << i-1 << endl;
            return 0;
        }
    }
}