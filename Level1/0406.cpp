#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int n;
    set<int> x;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
        if(x.find(A[i]) != x.end()){
            cout << "NO" << endl;
            return 0;
        }
        x.insert(A[i]);
    }

    sort(A, A + n);
    int diff = A[1]-A[0];
    for(int i = 1; i < n-1; i++){
        if(A[i+1] - A[i] != diff){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}