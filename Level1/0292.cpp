#include<iostream>
#include<string>
using namespace std;

int main(){
    char A[51];
    int t, u;
    scanf("%s %d %d", A, &t, &u);
    string S = A;
    if(t == u){
        S.erase(S.begin() + t);
    }else{
        S.erase(S.begin() + max(t,u));
        S.erase(S.begin() + min(t,u));
    }

    cout << S << endl;
    return 0;
}