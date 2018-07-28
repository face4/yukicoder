#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int minimum = 1000000, maximum;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    maximum = a[n-1] - a[0];
    for(int i = 0; i < n-1; i++){
        minimum = min(minimum, a[i+1]-a[i]);
    }

    cout << minimum << endl << maximum << endl;
    
    return 0;
}