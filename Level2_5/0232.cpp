#include<iostream>
using namespace std;

int main(){
    int t, a, b;
    cin >> t >> a >> b;

    if(t < max(a,b) || (t == 1 && a+b == 0)){
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    int u[100000] = {}, r[100000] = {};
    
    for(int i = 0; i < a; i++)  u[i] = 1;
    for(int i = a; i+1 < t; i += 2) u[i] = 1, u[i+1] = -1;
    for(int i = 0; i < b; i++)  r[t-1-i] = 1;
    for(int i = b; i+1 < t; i += 2) r[t-1-i] = 1, r[t-i-2] = -1;

    for(int i = 0; i < t; i++){
        if(u[i] == 1)   printf("^");
        if(u[i] == -1)  printf("v");
        if(r[i] == 1)   printf(">");
        if(r[i] == -1)  printf("<");
        printf("\n");
    }

    return 0;
}