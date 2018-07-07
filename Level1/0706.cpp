#include<iostream>
using namespace std;

int main(){
    int n;
    int A[1000] = {};

    string x;

    cin >> n;
    while(n-- > 0){
        cin >> x;
        A[x.length()-2]++;
    }

    int mode = -1;
    int ans;
    for(int i = 998; i >= 0; i--){
        if(A[i] > mode){
            mode = A[i];
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}