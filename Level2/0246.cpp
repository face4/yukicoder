#include<iostream>
using namespace std;

int main(){
    int left = 1, right = 1e9+1, mid, res;
    while(left + 1 < right){
        int mid = (left+right)/2;
        cout << "? " << mid << endl << flush;
        cin >> res;
        if(res == 1)        left = mid;
        else if(res == 0)   right = mid;
    }

    cout << "! " << left << endl;
    return 0;
}