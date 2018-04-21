#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int A[100] = {}, B[101] = {}, n, x;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    
    for(int i = 0; i < n; i++){
        cin >> x;
        B[x] += A[i];
    }

    int *min = max_element(B, B + 101);
    if(min == B)    cout << "YES";
    else            cout << "NO";
    cout << endl;

    return 0;
}