#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double A[n], b;
    cin >> b;
    for(int i = 0; i < n; i++)  cin >> A[i];

    double diff = 0, inte = 0;
    for(int i = 0; i < n; i++){
        diff += A[i] * pow(b, A[i]-1.0);
        if(A[i] == -1.0){
            inte += log(abs(b));
        }else{
            inte += pow(b, A[i]+1.0)/(A[i]+1.0);
        }
    } 

    cout << fixed << setprecision(4);
    cout << diff << endl << inte << endl;
    return 0;
}