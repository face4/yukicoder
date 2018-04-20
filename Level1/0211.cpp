#include<iostream>
#include<iomanip> // I/O manipulator
using namespace std;

int main(){
    int count = 0, k;
    cin >> k;
    int A[6] = {2,3,5,7,11,13};
    int B[6] = {4,6,8,9,10,12};
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(A[i]*B[j] == k)    count++;
        }
    }

    cout << setprecision(12) << (count / 36.0) << endl;
    return 0;
}