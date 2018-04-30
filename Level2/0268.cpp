#include<iostream>
using namespace std;

int main(){
    int l1, l2, l3, A[3], B[3];
    cin >> l1 >> l2 >> l3 >> B[0] >> B[1] >> B[2];
    A[0] = l1+l2;   A[1] = l2+l3;   A[2] = l3+l1;

    int ans = 60001;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j)  continue;
            for(int k = 0; k < 3; k++){
                if(i == k || j == k)    continue;
                ans = min(ans, A[i]*B[0] + A[j]*B[1] + A[k]*B[2]);
            }
        }
    }

    ans *= 2;
    cout << ans << endl;
    return 0;
}