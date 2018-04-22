#include<iostream>
using namespace std;

int main(){
    int n , k;
    cin >> n >> k;
    char A[n+1];
    cin >> A;
    int diff = 0, x;
    if(A[k-1] == ')'){
        for(x = k-2; x >= 0; x--){
            if(A[x] == '('){
                if(diff == 0){
                    break;
                }
                diff--;
            }else if(A[x] == ')'){
                diff++;
            }
        }
    }else if(A[k-1] == '('){
        for(x = k; x < n; x++){
            if(A[x] == ')'){
                if(diff == 0){
                    break;
                }
                diff--;
            }else if(A[x] == '('){
                diff++;
            }
        }
    }

    cout << x+1 << endl;
    return 0;
}