#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int one[3], four[3];
    char c;
    for(int i = 0; i < 3; i++){
        cin >> c;
        if(c == '?'){
            one[i] = 1;
            four[i] = 4;
        }else{
            int x = (int)(c-'0');
            one[i] = x;
            four[i] = x;
        }
    }

    // one check
    if((one[1]-one[0])*(one[1]-one[2]) > 0){
        cout << "1"; 
    }
    
    // four check
    if((four[1]-four[0])*(four[1]-four[2]) > 0){
        cout << "4"; 
    }
    
    cout << endl;
    return 0;
}