#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            int tmp = 0;
            while(n%i == 0){
                tmp++;
                n /= i;
            }
            ans ^= tmp;
        }
    }
    if(n != 1)  ans ^= 1;
    
    if(ans == 0){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
    }

    return 0;
}