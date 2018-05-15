#include<iostream>
using namespace std;

int A[100000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> A[i];

    int pos = n;
    int count = 0;
    for(int i = n-1; i >= 0; i--){
        if(pos == A[i]){
            pos--;
            count++;
        }
    }

    cout << n-count << endl;
    return 0;
}