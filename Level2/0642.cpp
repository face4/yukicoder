#include<iostream>
using namespace std;

int main(){
    int count = 0;
    int n;
    cin >> n;
    while(n != 1){
        if(n & 1 == 1){
            n++;
            count++;
        }else{
            n = n>>1;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}