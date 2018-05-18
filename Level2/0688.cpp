#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int main(){
    int k;
    cin >> k;

    int i, j;
    bool br = false;
    for(i = 1; i <= 30; i++){
        for(j = 1; j <= i; j++){
            if(j%2==0 && j/2*(j-1)*round(pow(2,(i-j))) == k){
                br = true;
                break;
            }else if(j%2==1 && (j-1)/2*j*round(pow(2,(i-j))) == k){
                br = true;
                break;
            } 
        }
        if(br) break;
    }

    cout << i << endl;
    if(i == j){
        cout << 1;
        for(int x = 1; x < i; x++){
            cout << " " << 1;
        }
        cout << endl;
    }else{
        cout << 0;
        for(int x = 1; x < i-j; x++){
            cout << " " << 0;
        }
        for(int x = 0; x < j; x++){
            cout << " " << 1;
        }
        cout << endl;
    }

    return 0;
}