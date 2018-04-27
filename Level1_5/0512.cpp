#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int x, y, n;
    cin >> x >> y >> n;
    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];
    for(int i = 0; i < n; i++)  A[i] *= 100;
    
    for(int i = 0; i < n-1; i++){
        if(((double)A[i]* y) > A[i+1] * x){
            cout << "NO" << endl;
            return 0; 
        }
    }

    cout << "YES" << endl;
    return 0;
}