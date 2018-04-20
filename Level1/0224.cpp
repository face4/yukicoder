#include<iostream>
using namespace std;

int main(){
    int n, res = 0;
    scanf("%d" , &n);
    char S[n+1], T[n+1]; // null終端文字列用に+1したけど、無くても動いた.
    scanf("%s %s", S, T);
    for(int i = 0; i < n; i++){
        if(S[i] != T[i]) res++;
    }
    printf("%d\n", res);
    return 0;
}